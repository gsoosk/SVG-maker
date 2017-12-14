#ifndef CANVAS_H
#define CANVAS_H
#include <string>
#include <vector>
#include "Shape.h"
#include "Rules.h"
#include "Circle.h"
#include "Rectangle.h"
#include "BadException.h"
#include "Line.h"
#include "Text.h"
#include "Group.h"
#include "SVGCreator.h"
class Canvas
{
public:
	Canvas(std::vector<std :: string> _initCoordinates);
	void draw_a_shape(std::string shapeName, std::string shapeType, std::string CommandLine);
	void draw_a_circle(std::string shapeName, std::vector<std::vector<std::string> > attributes);
	void draw_a_rectangle(std::string shapeName, std::vector<std::vector<std::string> > attributes);
	void draw_a_line(std::string shapeName, std::vector<std::vector<std::string> > attributes);
	void draw_a_text(std::string shapeName, std::vector<std::vector<std::string> > attributes);
	void make_a_group(std::string groupName, std::vector<std::vector<std::string> > attributes);
	void delete_group(std::string groupName);
	void move(std::string objectName, std::string groupName);
	void list(std::string groupName);
	void export_to_file(std::string fileName);
	void bring_up(std::string objectName);
	void bring_down(std::string objectName);
	void touch(std::string objectName, std::string att, std::string value);
	
	//~Canvas();
private:
	std::vector<std :: string> initCoordinates;
	std::vector<Shape*> shapes;
	Group* mainGroup;
	std::vector<Group*> groups;

	//private methods
	std:: string num_of_shapes_with_certian_type(std::string typeName);
	std:: string num_of_groups_without_name();
	void delete_parent_for_all_shapes_and_groups(Group* parent);
	Group* find_to_group(std::string toGroupName);
	bool move_group(std::string groupName, Group* toGroup);
	bool move_shape(std::string shapeName, Group* toGroup);



	
};
#endif