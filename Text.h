#ifndef TEXT_H
#define TEXT_H
#include "Shape.h"
#include "Group.h"
#include <string>
#include <vector>
#include "Rules.h"
class Text : public Shape 
{
public:
	Text(std::string _name, Group* group, std::string _text, std::vector <std::string> _position);
	bool does_it_match_type(std::string typeName);
	std::vector<std::vector<std::string> > get_att_and_merge_from_parents();
	std::string get_text();
	std::vector<std::string> get_pos();
	void change_att(std::string att, std::string value);

private:
	std::string text;
	std::vector<std::string> position;
	
	
};
#endif