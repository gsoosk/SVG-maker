#ifndef RECTANGLE_H
#define RECTANGLE_H
#include <string>
#include <vector>
#include "Shape.h"
#include "Group.h"
#include "Rules.h"
class Rectangle : public Shape
{
public:
	Rectangle(std::string _name, Group* _group, std::vector<std::vector<std::string> > _points);
	bool does_it_match_type(std::string typeName); 
	std::vector<std::vector<std::string> > get_att_and_merge_from_parents();
	void change_att(std::string att, std::string value);
private:
	std::string name;
	std::vector<std::vector<std::string> > points;
	
	
};
#endif