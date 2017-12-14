#include "SVGCreator.h"
using namespace std;

SVGCreator :: SVGCreator(Group* _mainGroup, vector<string> _initCoordinates, vector<Shape*> _shapes, vector<Group*> _groups)
{
	mainGroup = _mainGroup;
	initCoordinates = _initCoordinates;
	shapes = _shapes;
	groups = _groups;
	
}
void SVGCreator :: make_svg(string fileName)
{
	string svg = "<?xml version=\"1.0\" standalone=\"no\"?> <!DOCTYPE svg PUBLIC \"-//W3C//DTD SVG 1.1//EN\" \"http://www.w3.org/Graphics/SVG/1.1/DTD/svg11.dtd\"><svg version=\"1.1\" xmlns=\"http://www.w3.org/2000/svg\">";
	for(int i=0; i<shapes.size() ; i++)
	{
		if(shapes[i] -> does_it_match_type("circle"))
			svg += this -> make_tag(shapes[i],"circle");
		else if(shapes[i] -> does_it_match_type("line"))
			svg += this -> make_tag(shapes[i],"line");
		else if(shapes[i] -> does_it_match_type("rectangle"))
			svg += this -> make_tag(shapes[i],"rect");
		else if(shapes[i] -> does_it_match_type("text"))
			svg += this -> make_tag(shapes[i],"text");
	}
	svg += "</svg>";
	ofstream SVGFile;
	SVGFile.open(fileName);
	if(!SVGFile)
	{
		cerr<<"could not open file";
	}
	else
	{
		SVGFile << svg ;
	}
	SVGFile.close();
}
string SVGCreator :: make_tag(Shape* shapeForMake, string type)
{
	string tag = "<"+ type+ " ";
	
	vector<vector<string> > allAtts ;
	allAtts = this -> get_all_atts(shapeForMake);
	vector <string> position = shapeForMake -> get_position_from_parents_of_group();
	// cerr << position[0] << " "<<position[1] <<endl;
	for(int i=0; i < allAtts.size() ; i++)
	{

		if(allAtts[i][0]=="center")
			this -> append_to_tag_center(tag, allAtts[i][1], position);
		else if(allAtts[i][0]=="radius")
			this -> append_to_tag_a_value(tag, allAtts[i][1], "r");
		else if(allAtts[i][0]=="color")
			this -> append_to_tag_a_value(tag, allAtts[i][1], "fill");
		else if(allAtts[i][0]=="border")
			this -> append_to_tag_border(tag, allAtts[i][1]);
		else if(allAtts[i][0]=="opacity")
			this -> append_to_tag_a_value(tag, allAtts[i][1], "opacity");
		else if(allAtts[i][0]=="rotate")
			this -> append_to_tag_a_value(tag, "rotate(" + allAtts[i][1] + ")" , "transform");
		else if(allAtts[i][0]=="points")
			this -> append_to_tag_points(tag, allAtts[i][1], shapeForMake, position);
		else if(allAtts[i][0]=="font")
			this -> append_to_tag_font(tag, allAtts[i][1]);
	}
	if(shapeForMake -> does_it_match_type("text"))
	{
		vector<string> pos = shapeForMake -> get_pos();

		tag += "x=\"" + to_string(atoi(pos[0].c_str()) + atoi(position[0].c_str()))+"\" y=\"" + to_string(atoi(pos[1].c_str()) + atoi(position[1].c_str()))+"\" >" ;
		tag += shapeForMake -> get_text();
		tag += "</text>";
	}
	else
		tag+= "/>";

	return tag;
}
vector<vector<string> > SVGCreator :: get_all_atts(Shape* shapeForMake)
{
	//If it has an attribute it use uppest with that att else it use uppest force group's attribute
	vector<vector<string> > ownAttributes = shapeForMake -> get_att_and_merge_from_parents();
	vector<vector<string> > notOwnAttributes;
	shapeForMake -> make_not_own_att_from_parents(notOwnAttributes, ownAttributes);
	vector<vector<string> > allAtts;
	for(int i=0; i<ownAttributes.size(); i++)
		allAtts.push_back(ownAttributes[i]);
	for(int i=0; i<notOwnAttributes.size(); i++)
		allAtts.push_back(notOwnAttributes[i]);
	return allAtts;
}
void SVGCreator :: append_to_tag_center(string &tag, string value, vector<string> position)
{
	tag+= "cx=";
	vector<string> pos;
	pos = Rules::valid_coordinates(value);
	tag +=  "\"" + to_string(atoi(pos[0].c_str()) + atoi(position[0].c_str())) + "\"" +" ";
	tag += "cy=";
	tag += "\"" + to_string(atoi(pos[1].c_str()) + atoi(position[1].c_str())) + "\"" +" ";
	
}
void SVGCreator :: append_to_tag_a_value(string &tag, string value, string att)
{
	tag+= att + "=";
	tag+= "\"" + value + "\" ";
}
void SVGCreator :: append_to_tag_border(string &tag, string value)
{
	Rules::get_sub_str_from_line(value, '<');
	string color = Rules::get_sub_str_from_line(value,',');
	string width = Rules::get_sub_str_from_line(value, '>');
	tag += "storke=\"" + color+ "\" stroke-width=\"" + width + "\" ";
}
void SVGCreator :: append_to_tag_points(string &tag, string value, Shape* shapeForMake, vector<string> position)
{
	if(shapeForMake -> does_it_match_type("rectangle"))
	{
		vector<vector<string> > points = Rules::valid_array_of_coordinates(value);
		tag+= "x=\"" + to_string(atoi(points[0][0].c_str()) + atoi(position[0].c_str())) + "\" ";
		tag+= "y=\"" + to_string(atoi(points[0][1].c_str()) + atoi(position[1].c_str())) + "\" ";
		tag+= "width=\"" + to_string(atoi(points[1][0].c_str()) + atoi(points[0][0].c_str())) + "\" ";
		tag+= "height=\"" + to_string(atoi(points[1][1].c_str()) + atoi(points[0][1].c_str())) + "\" ";
	}
	else if(shapeForMake -> does_it_match_type("line"))
	{
		vector<vector<string> > points = Rules::valid_array_of_coordinates(value);
		tag+= "x1=\"" + points[0][0] + "\" ";
		tag+= "y1=\"" + points[0][1] + "\" ";
		tag+= "x2=\"" + points[1][0] + "\" ";
		tag+= "y2=\"" + points[1][1] + "\" ";
	}
}
void SVGCreator :: append_to_tag_font(string &tag, string value)
{
	Rules::get_sub_str_from_line(value, '<');
	string font_name = Rules::get_sub_str_from_line(value,',');
	string size = Rules::get_sub_str_from_line(value, '>');
	tag += "font_family=\"" + font_name + "\" font_size=\"" + size + "\" ";
}