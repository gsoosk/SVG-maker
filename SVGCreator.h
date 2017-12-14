#ifndef SVG_CREATOR_H
#define SVG_CREATOR_H
#include "Group.h"
#include "Shape.h"
#include <vector>
#include <string>
#include <iostream>
#include "Rules.h"
#include <fstream>
class SVGCreator
{
public:
	SVGCreator(Group* _mainGroup, std::vector<std :: string> _initCoordinates, std::vector<Shape*> _shapes, std::vector<Group*> _groups);
	void make_svg(std::string fileName);
	// ~SVGCreator();
private:
	Group* mainGroup;
	std::vector<std :: string> initCoordinates;
	std::vector<Shape*> shapes;
	std::vector<Group*> groups;
	

	//private methods:
	std::string make_tag(Shape* shapeForMake, std::string type);
	std::vector<std::vector<std::string> > get_all_atts(Shape* shapeForMake);
	void append_to_tag_center(std::string &tag, std::string value, std::vector<std::string> position);
	void append_to_tag_a_value(std::string &tag, std::string value, std::string att);
	void append_to_tag_border(std::string &tag, std::string value);
	void append_to_tag_points(std::string &tag, std::string value, Shape* shapeForMake, std::vector<std::string> position);
	void append_to_tag_font(std::string &tag, std::string value);



};
#endif 