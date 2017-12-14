#ifndef CIRCLE_H
#define CIRCLE_H
#include "Shape.h"
#include <string>
#include <vector>
#include "Group.h"
#include "Rules.h"
class Circle : public Shape 
{
public:
	Circle(std::string _name, Group* _group, std::string _radius, std::vector <std::string> _center);
	bool does_it_match_type(std::string typeName);
	std::vector<std::vector<std::string> > get_att_and_merge_from_parents();
	void change_att(std::string att, std::string value);
	
private:
	std::string radius;
	std::vector<std::string> center;

	
};
#endif