#include "functions.h"
#include "modules.h"
bool runState = true;
int main(int argc, char** argv) {
	functionLibrary Program;
	cout << "\e[1mopenDATA Build 100\e[0m\n\nType 'help' for more commands\n\n";
	while(runState = true) {
		Program.commandline(runState);
	}
	return 0;
}
