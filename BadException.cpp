#include "BadException.h"

using namespace std;

BadException :: BadException(string msg)
{
	massage = msg;
}
void BadException:: print_msg()
{
	cout << massage << endl;
}