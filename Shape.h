#ifndef SHAPE_H
#define SHAPE_H
#include <string>
#include <vector>
#include "Group.h"
class Shape
{
public:
	Shape(std:: string _name, Group* _group);
	bool does_it(std::string _name);
	virtual bool does_it_match_type(std::string typeName) = 0; 
	void append_some_att(std::vector<std::vector<std::string> > v);
	Group* get_parent();
	void set_parent(Group* newGroup);
	std::string get_name();
	virtual std::vector<std::vector<std::string> > get_att_and_merge_from_parents() = 0 ;
	std::string find_att_from_parents(std::string attName);
	void make_not_own_att_from_parents(std::vector<std::vector<std::string> > &notOwnAttributes, std::vector<std::vector<std::string> > ownAttributes);
	std::vector<std::string> get_position_from_parents_of_group();
	virtual std::string get_text();
	virtual std::vector<std::string> get_pos();
	virtual void change_att(std::string att, std::string value) = 0;

	// ~Shape();
private: 
	std :: string name;
	Group* group;	
protected:
	std::vector<std::vector<std::string> > attributes;
};
#endif