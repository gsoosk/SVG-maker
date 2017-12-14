#include "Bob.h"
using namespace std;

int main()
{
	CommandHandler robotCommandHandler;

	string CommandLine;
	string allCommands="";
	getline(cin,CommandLine);
	while(CommandLine!="")
	{
		robotCommandHandler.listen(CommandLine);
		getline(cin,CommandLine);
	}
}