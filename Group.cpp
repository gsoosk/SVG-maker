#include "Group.h"
using namespace std;
#include <iostream>
Group :: Group(string _name, vector<string> _position, Group* p)
{
	name = _name;
	position = _position;
	parent = p;
	inherit = DEFAULT;
}
Group :: Group(string _name, vector<string> _position, Group* p, bool _inherit)
{
	name = _name;
	position = _position;
	parent = p;
	inherit = _inherit;
}
bool Group :: does_it(string _name)
{
	return name == _name ;
}
void Group :: append_some_att(vector<vector<string> > _attributes)
{
	for(int i=0; i<_attributes.size(); i++)
		attributes.push_back(_attributes[i]);
}
Group* Group :: get_parent()
{
	return parent;
}
void Group :: set_parent(Group* newParent)
{
	parent = newParent;
}
string Group :: get_name()
{
	return name;
}
string Group :: find_att_from_parents(string attName)
{
	if(parent == NULL)
		return "";
	string parentAttValue = parent -> find_att_from_parents(attName) ;
	if(parentAttValue == "")
	{
		for(int i=0 ; i<attributes.size() ; i++)
		{
			if(attributes[i][0] == attName)
				return attributes[i][1];
		}
	}
	return parentAttValue;

}
bool Group :: make_not_own_att_from_parents(vector<vector<string> > &notOwnAttributes, vector<vector<string> > ownAttributes)
{
	if(parent == NULL)
		return true;
	parent -> make_not_own_att_from_parents(notOwnAttributes, ownAttributes);
	if(inherit == FORCE)
	{
		for(int i=0; i<attributes.size(); i++)
		{
			bool exists = false;
			for(int j=0; j<notOwnAttributes.size(); j++)
			{
				if(notOwnAttributes[j][0] == attributes[i][0])
				{
					exists = true ;
					break;
				}
			}
			if(!exists)
				for(int j=0; j<ownAttributes.size(); j++)
				{
					if(ownAttributes[j][0] == attributes[i][0])
					{
						exists = true;
						break;
					}
				}
			if(!exists)
			{
				notOwnAttributes.push_back(attributes[i]);
			}
		}
	}
	return true;
}
vector<string> Group:: get_position_from_parents()
{
	if(parent == NULL)
	{
		vector<string> pos;
		pos.push_back("0");
		pos.push_back("0");
		return pos;
	}
	vector<string> pos = parent -> get_position_from_parents();
	pos[0] = to_string(atoi(pos[0].c_str()) + atoi(position[0].c_str()));
	pos[1] = to_string(atoi(pos[1].c_str()) + atoi(position[1].c_str()));
	return pos;
}
void Group :: change_att(string att, string value)
{
	if(att == "position")
	{
		position = Rules::valid_coordinates(value);
	}
	else if(att == "inherit")
	{
		if(value == "force")
			inherit = FORCE;
		else if(value == "default")
			inherit = DEFAULT;
	}
	for(int i =0 ;i<attributes.size(); i++)
	{
		if(attributes[i][0] == att)
		{

			attributes[i][1] = value;
			break;
		}
	}
}
