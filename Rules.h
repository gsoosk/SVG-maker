#ifndef RULES_H
#define RULES_H
#include <vector>
#include <string>
#include <iostream>
#define UNVALID_COORDINATES "-1"
#define SHAPE1 "circle"
#define SHAPE2 "rectangle"
#define SHAPE3 "line"
#define SHAPE4 "text"
#define TYPE1 "svg"
class Rules
{
public:
	static std::vector<std::string> valid_coordinates(std::string coordinate);
	static std::string get_sub_str_from_line(std::string &Line,char character);
	static bool does_it_valid_type_of_shape(const std::string &shapeType);
	static std::vector<std::vector<std::string> > seperate_attributes(std::string &commandLine);
	static std::vector<std::vector<std::string> > valid_array_of_coordinates(std::string arrayOfCoordinates);
	static bool does_it_valid_name_for_file_to_export(std::string fileName);
	
	
};
#endif