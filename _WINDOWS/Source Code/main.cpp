#include "functions.h"
#include "modules.h"
bool runState = true;
main(int argc, char** argv) {
	functionLibrary Program;
	cout << "\e[1mopenDATA Build 100\e[0m\nWritten by jaxxmelbourne27\n\nType 'help' for more commands\n\n";
	while(runState = true) {
		Program.commandline();
	}
}
