#include "Rules.h"
using namespace std;

string Rules:: get_sub_str_from_line(string &Line,char character)
{
	bool there_is_char=false;
	for(int i=0; i<Line.size(); i++)
		if(Line[i]==character)
		{
			there_is_char=true;
			break;
		}
	if(there_is_char==true)
	{
		int CommaNumber= Line.find(character);
		string SubString= Line.substr(0,CommaNumber);
		string newLine= Line.substr(CommaNumber+1);
		Line= newLine;
		return SubString;
	} else
	{
		string SubString= Line;
		string newLine= "";
		Line= newLine;
		return SubString;
	}

}

vector<string> Rules :: valid_coordinates(string coordinate)
{
	vector<string> returnCoordinates(2);
	returnCoordinates[0] = UNVALID_COORDINATES;
	returnCoordinates[1] = UNVALID_COORDINATES;
	if(coordinate[0] == '<')
	{
		Rules:: get_sub_str_from_line(coordinate, '<');
		int X = atoi(Rules :: get_sub_str_from_line(coordinate, ',').c_str());
		if(X != 0)
			returnCoordinates[0] = to_string(X);
		int Y = atoi(Rules :: get_sub_str_from_line(coordinate, '>').c_str());
		if(Y != 0)
			returnCoordinates[1] = to_string(Y);
	}
	return returnCoordinates;
	
}
bool Rules:: does_it_valid_type_of_shape(const string &shapeType)
{
	if(shapeType != SHAPE1 && shapeType != SHAPE2 && shapeType != SHAPE3 && shapeType != SHAPE4)
		return false;
	return true;
}
vector<vector<string> > Rules:: seperate_attributes(string &commandLine)
{
	std::vector<vector<string> > v;
	while(commandLine != "")
	{
		string oneAtt;
		oneAtt = Rules::get_sub_str_from_line(commandLine, ' ');
		if(oneAtt[oneAtt.size()-1] == ',')
			oneAtt = oneAtt.substr(0, oneAtt.size() - 1);
		vector<string> singleAtt;
		singleAtt.push_back(Rules::get_sub_str_from_line(oneAtt, '='));
		singleAtt.push_back(oneAtt);
		v.push_back(singleAtt);
	}
	return v;
}
vector<vector<string> > Rules :: valid_array_of_coordinates(string arrayOfCoordinates)
{
	vector<vector<string> >  returnVect;
	Rules::get_sub_str_from_line(arrayOfCoordinates, '[');
	while(arrayOfCoordinates != "]")
	{	
		if(arrayOfCoordinates[0] == ',')
			Rules::get_sub_str_from_line(arrayOfCoordinates, ',');
		Rules::get_sub_str_from_line(arrayOfCoordinates, '<');
		vector<string> tmp;
		int X = atoi(Rules :: get_sub_str_from_line(arrayOfCoordinates, ',').c_str());
		if(X != 0)
			tmp.push_back(to_string(X));
		else
			tmp.push_back("-1");
		int Y = atoi(Rules :: get_sub_str_from_line(arrayOfCoordinates, '>').c_str());
		if(Y != 0)
			tmp.push_back(to_string(Y));
		else
			tmp.push_back("-1");
		returnVect.push_back(tmp);
	}
	return returnVect;

}
bool Rules :: does_it_valid_name_for_file_to_export(string fileName)
{
	string exactFileName = Rules::get_sub_str_from_line(fileName, '.');
	string fileType = fileName;
	if(fileType != TYPE1)
		return false;
	return true;
}