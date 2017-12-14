#ifndef GROUP_H
#define GROUP_H
#include <vector>
#include <string>
#include "Rules.h"
#define DEFAULT 1
#define FORCE 0
class Group
{
public:
	Group(std::string _name, std::vector<std::string> _position, Group* p);
	Group(std::string _name, std::vector<std::string> _position, Group* p, bool _inherit);
	bool does_it(std::string _name);
	void append_some_att(std::vector<std::vector<std::string> > _attributes);
	Group* get_parent();
	void set_parent(Group* newParent);
	std::string get_name();
	std::string find_att_from_parents(std::string attName);
	bool make_not_own_att_from_parents(std::vector<std::vector<std::string> > &notOwnAttributes, std::vector<std::vector<std::string> > ownAttributes);
	std::vector<std::string> get_position_from_parents();
	void change_att(std::string att, std::string value);
private:
	std::string name;
	std::vector<std::vector<std::string> > attributes;
	std::vector<std::string> position;
	Group* parent;
	bool inherit;
	
};
#endif