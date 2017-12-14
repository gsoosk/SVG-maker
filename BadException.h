#ifndef BAD_EXCEPTION_H
#define BAD_EXCEPTION_H
#include <string>
#include <iostream>
#define INIT_ERR "You should start with init command."
#define INIT_USED_ERR "You can not use init again."
#define BAD_COOR_ERR "unvalide coordinates."
#define BAD_COMMAND_ERR "Bad Command!"
#define UNVALID_SHAPE_TYPE "You use an unvalid shape type! please change it."
#define NO_ATTRIBUTE "Your shape should have some attribute!"
#define NAME_EXISTS "This name exists. change it!"
#define CIRCLE_ATT_NOT_FOUND "Attributes for radius or center not found."
#define REC_ATT_NOT_FOUND "Attributes for points not found."
#define TEXT_ATT_NOT_FOUND "Attributes for position not found."
#define GROUP_ATT_NOT_FOUND "Attributes for position not found."
#define BAD_VALUE_FOR_INHERIT "You use something wrong for inherit."
#define NO_GP_NAME_FOUND "You should write group name."
#define NAME_DOES_NOT_EXISTS "This name does not exists!"
#define NO_GP_TO_MOVE "No group found with this name to move!"
#define NO_OBJ_TO_MOVE "No object found with this name to move!"
#define NO_GP "No group found with this name."
#define BAD_FILE_INPUT "You use wrong format for file name."

class BadException
{
public:
	BadException(std::string msg);
	void print_msg();
private:
	std::string massage;
	
};
#endif