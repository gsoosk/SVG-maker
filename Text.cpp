#include "Text.h"
using namespace std;
Text::Text(string _name, Group* _group, string _text, vector <string> _position): Shape(_name, _group)
{
	text = _text;
	position = _position;
}
bool Text :: does_it_match_type(string typeName)
{
	return typeName == "text";
}
vector<vector<string> > Text :: get_att_and_merge_from_parents()
{
	vector<vector<string> > returnValue;
	string newText = this -> find_att_from_parents("text");
	if(newText != "")
	{
		vector<string> tmp;
		tmp.push_back("text");
		tmp.push_back(newText);
		returnValue.push_back(tmp);
	}
	else
	{
		vector<string> tmp;
		tmp.push_back("text");
		tmp.push_back(text);
		returnValue.push_back(tmp);
	}
	for(int i=0; i<attributes.size(); i++)
	{
		string newAtt = this -> find_att_from_parents(attributes[i][0]);
		if(newAtt != "")
		{
			vector<string> tmp;
			tmp.push_back(attributes[i][0]);
			tmp.push_back(newAtt);
			returnValue.push_back(tmp);
		}
		else
		{
			vector<string> tmp;
			tmp.push_back(attributes[i][0]);
			tmp.push_back(attributes[i][1]);
			returnValue.push_back(tmp);
		}
	}
	return returnValue;
}
string Text:: get_text()
{
	return text;
}
vector<string> Text:: get_pos()
{
	return position;
}
void Text :: change_att(string att, string value)
{
	if(att == "position")
	{
		position = Rules::valid_coordinates(value);
	}
	else if(att == "text")
	{
		text = value;
	}
	else
	{
		for(int i =0 ;i<attributes.size(); i++)
		{
			if(attributes[i][0] == att)
			{

				attributes[i][1] = value;
				break;
			}
		}
	}
}