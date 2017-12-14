#ifndef COMMAND_HANDLER_H
#define COMMAND_HANDLER_H
#include <iostream>
#include <string>
#include <vector>
#include "Rules.h"
#include "Canvas.h"
#include "BadException.h"
#include <fstream>
#define INIT_CM "init"
#define DRAW_CM "draw"
#define ATT_SEPERATOR "with"
#define GROUP_CM "group"
#define UNGROUP_CM "ungroup"
#define MOVE_CM "move"
#define LIST_CM "list"
#define EXPORT_CM "export"
#define BRING_CM "bring"
#define TOUCH_CM "touch"
#define SAVE_CM "save"

class CommandHandler
{
public:
	CommandHandler();
	// ~CommandHandler();
	void listen(std::string CommandLine);
	void do_command_init(std:: string CommandLine);
	void do_command_draw(std:: string CommandLine);
	void do_command_group(std:: string CommandLine);
	void do_command_ungroup(std:: string CommandLine);
	void do_command_move(std:: string CommandLine);
	void do_command_list(std:: string CommandLine);
	void do_command_export(std:: string CommandLine);
	void do_command_bring(std:: string CommandLine);
	void do_command_touch(std:: string CommandLine);

private:
	bool initUsed;
	Canvas* bobCanvas;
	std::string allCommands;
};
#endif