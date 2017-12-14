#include "Shape.h"

using namespace std;

Shape :: Shape(string _name, Group* _group)
{
	name = _name;
	group = _group;

}
bool Shape:: does_it(string _name)
{
	return _name == name;
}
Group* Shape :: get_parent()
{
	return group;
}
void Shape :: set_parent(Group* newParent)
{
	group = newParent;
}
string Shape :: get_name()
{
	return name;
}
void Shape :: append_some_att(vector<vector<string> > v)
{
	for(int i=0; i<v.size(); i++)
		attributes.push_back(v[i]);
}
string Shape :: find_att_from_parents(string attName)
{
	return this -> group -> find_att_from_parents(attName);
}
void Shape :: make_not_own_att_from_parents(vector<vector<string> > &notOwnAttributes, vector<vector<string> > ownAttributes)
{
	this -> group -> make_not_own_att_from_parents(notOwnAttributes, ownAttributes);
}
vector<string> Shape :: get_position_from_parents_of_group()
{
	return group -> get_position_from_parents();
}
std::string Shape ::get_text()
{
	return "";
}
std::vector<std::string> Shape:: get_pos()
{
	std::vector<string> v;
	return v;
}
