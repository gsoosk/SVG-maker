#include "Circle.h"
using namespace std;
Circle::Circle(string _name, Group* _group, string _radius, vector <string> _center): Shape(_name, _group)
{
	radius = _radius;
	center = _center;
}
bool Circle :: does_it_match_type(string typeName)
{
	return typeName == "circle";
}
vector<vector<string> > Circle:: get_att_and_merge_from_parents()
{
	vector<vector<string> > returnValue;
	//first we check radius and center :
	string newCenter = this -> find_att_from_parents("center");
	if(newCenter != "")
	{
		vector<string> tmp;
		tmp.push_back("center");
		tmp.push_back(newCenter);
		returnValue.push_back(tmp);
	}
	else
	{
		vector<string> tmp;
		tmp.push_back("center");
		tmp.push_back("<" + center[0] + "," + center[1] + ">");
		returnValue.push_back(tmp);
	}
	string newRadius = this -> find_att_from_parents("radius");
	if(newRadius != "")
	{
		vector<string> tmp;
		tmp.push_back("radius");
		tmp.push_back(newRadius);
		returnValue.push_back(tmp);
	}
	else
	{
		vector<string> tmp;
		tmp.push_back("radius");
		tmp.push_back(radius);
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
void Circle :: change_att(string att, string value)
{
	if(att == "center")
	{
		center = Rules::valid_coordinates(value);
	}
	else if(att == "radius")
	{
		radius = value;
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