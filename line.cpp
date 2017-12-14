#include "Line.h"
using namespace std;
Line :: Line(string _name, Group* _group, vector<vector<string> > _points): Shape(_name, _group)
{
	points = _points;
}

bool Line :: does_it_match_type(string typeName)
{
	return typeName == "line";
}
vector<vector<string> > Line:: get_att_and_merge_from_parents()
{
	vector<vector<string> > returnValue;
	//first we check radius and center :
	string newPoints = this -> find_att_from_parents("points");
	if(newPoints != "")
	{
		vector<string> tmp;
		tmp.push_back("points");
		tmp.push_back(newPoints);
		returnValue.push_back(tmp);
	}
	else
	{
		vector<string> tmp;
		tmp.push_back("points");
		tmp.push_back("[<" + points[0][0] +","+points[0][1]+">,<" + points[1][0] + "," + points [1][1] +">]");
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
void Line :: change_att(string att, string value)
{
	if(att == "points")
	{
		points = Rules::valid_array_of_coordinates(value);
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