#include "functions.h"
#include "modules.h"
bool runState = true;
main(int argc, char** argv) {
	functionLibrary Program;
	Program._init_();
	while(runState = true) {
		Program.commandline();
	}
}