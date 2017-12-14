#include "CommandHandler.h"


using namespace std;

CommandHandler :: CommandHandler()
{
	initUsed = false;
	bobCanvas = NULL;
	allCommands = "";

}

void CommandHandler :: listen(string CommandLine)
{
	string backUpCommandline = CommandLine;
	string command;
	command = Rules::get_sub_str_from_line(CommandLine , ' ');
	if(!initUsed)
	{
		try
		{
			if(command == INIT_CM)
			{
				this -> do_command_init(CommandLine);
				allCommands += backUpCommandline + "\n";
			}
			else 
				throw BadException(INIT_ERR);

		}		
		catch(BadException ex){
			ex.print_msg();
		}
	}
	else
	{
		try
		{
			if(command != SAVE_CM)
			{
				if(command == INIT_CM)
					this -> do_command_init(CommandLine);
				else if(command == DRAW_CM)
					this -> do_command_draw(CommandLine);
				else if(command == GROUP_CM)
					this -> do_command_group(CommandLine);
				else if(command == UNGROUP_CM)
					this -> do_command_ungroup(CommandLine);
				else if(command == MOVE_CM)
					this -> do_command_move(CommandLine);
				else if(command == LIST_CM)
					this -> do_command_list(CommandLine);
				else if(command == EXPORT_CM)
					this -> do_command_export(CommandLine);
				else if(command == BRING_CM)
					this -> do_command_bring(CommandLine);
				else if(command == TOUCH_CM)
					this -> do_command_touch(CommandLine);
				else
					throw BadException(BAD_COMMAND_ERR);
				allCommands += backUpCommandline + "\n";
			}
			else if(command == SAVE_CM)
			{
				ofstream File;
				File.open(CommandLine);
				if(!File)
				{
					throw BadException("could not open file");
				}
				File << allCommands;
				cout << "done!" <<endl;
			}
			

		}
		catch(BadException ex){
			ex.print_msg();
		}
		
	}
	

	
}
void CommandHandler :: do_command_init(string CommandLine) 
{
	try
	{
		if(initUsed)
			throw BadException(INIT_USED_ERR);
		string canvasDimension;
		canvasDimension = CommandLine;
		vector<string> coordinates = Rules::valid_coordinates(canvasDimension);
		if(coordinates[0] != "-1" && coordinates[1] != "-1")
		{
			initUsed = true;
			bobCanvas = new Canvas(coordinates);
		}
		else
			throw BadException(BAD_COOR_ERR);
	}
	catch(BadException ex)
	{
		ex.print_msg();
	}

}
void CommandHandler :: do_command_draw(string CommandLine)
{
	try
	{
		string shapeType = Rules::get_sub_str_from_line(CommandLine, ' ');
		if(!Rules::does_it_valid_type_of_shape(shapeType))
			throw BadException(UNVALID_SHAPE_TYPE);
		string shapeName = Rules::get_sub_str_from_line(CommandLine, ' ');
		if(shapeName == ATT_SEPERATOR)
			shapeName = "";
		else if(Rules::get_sub_str_from_line(CommandLine, ' ') != ATT_SEPERATOR)
			throw BadException(NO_ATTRIBUTE);
		bobCanvas -> draw_a_shape(shapeName, shapeType, CommandLine);
	}
	catch(BadException ex){
		ex.print_msg();
	}
}
void CommandHandler :: do_command_group(string CommandLine)
{
	try
	{
		string groupName = Rules::get_sub_str_from_line(CommandLine, ' ');
		if(groupName == ATT_SEPERATOR)
			groupName = "";
		else if(Rules::get_sub_str_from_line(CommandLine, ' ') != ATT_SEPERATOR)
			throw BadException(NO_ATTRIBUTE);
		vector<vector<string> > attributes = Rules::seperate_attributes(CommandLine);
		bobCanvas -> make_a_group(groupName, attributes);
	}
	catch(BadException ex){
		ex.print_msg();
	}
}
void CommandHandler :: do_command_ungroup(string CommandLine)
{
	try
	{
		if(CommandLine == "")
			throw BadException(NO_GP_NAME_FOUND);
		bobCanvas -> delete_group(CommandLine);
	}
	catch(BadException ex){
		ex.print_msg();
	}
}
void CommandHandler :: do_command_move(string CommandLine)
{
	try
	{
		string objectName = Rules::get_sub_str_from_line(CommandLine, ' ');
		string groupName;

		if(CommandLine == "")
			groupName = "";
		else if(Rules::get_sub_str_from_line(CommandLine, ' ') == "to")
		{
			groupName = CommandLine;
		}
		else
			throw BadException(BAD_COMMAND_ERR);
		bobCanvas -> move(objectName, groupName);

	}
	catch(BadException ex){
		ex.print_msg();
	}
}
void CommandHandler :: do_command_list(string CommandLine)
{
	try
	{
		string groupName = "";
		if(CommandLine != "")
			groupName = CommandLine;
		bobCanvas -> list(groupName);
	}
	catch(BadException ex)
	{
		ex.print_msg();
	}
}
void CommandHandler :: do_command_export(string CommandLine)
{
	try
	{
		string fileName = CommandLine;
		if(!Rules::does_it_valid_name_for_file_to_export(fileName))
			throw BadException(BAD_FILE_INPUT);
		bobCanvas -> export_to_file(fileName);
	}
	catch(BadException ex)
	{
		ex.print_msg();
	}
}
void CommandHandler :: do_command_bring(string CommandLine)
{
	string upOrDown = Rules::get_sub_str_from_line(CommandLine, ' ');
	if(upOrDown == "up")
		bobCanvas -> bring_up(CommandLine);
	else if(upOrDown == "down")
		bobCanvas -> bring_down(CommandLine);

}
void CommandHandler :: do_command_touch(string CommandLine)
{
	string name = Rules::get_sub_str_from_line(CommandLine, ' ');
	string att = Rules::get_sub_str_from_line(CommandLine, '=');
	string value = CommandLine;
	bobCanvas -> touch(name, att, value);

}