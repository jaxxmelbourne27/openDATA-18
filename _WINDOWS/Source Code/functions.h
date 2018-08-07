// Provides all main functions

#include "modules.h"
string directory, filename = "text.txt", line, alldata[1024], command, input, oldname;
char data[1024];
int i, lines = 0, writelines = 0, iffileexists, result, filesize;
class functionLibrary {
	public:
		void commandline() {
			cout << "> ";
			cin >> command;
			commandLibrary();
		}
		void inputfilename() {
			cout << "\e[1mPath to file + filename\e[0m: ";
			cin >> filename;
			cout << endl;
		}
		void readfile() {
			ifstream file;
			file.open(filename.c_str());
			getNoOfLines();
			for(i = 0; i < lines; i++) {
				getline(file, line);
				alldata[i] = line;
				cout << alldata[i] << endl;
			}
			file.close();
			cout << endl;
		}
		void writefile() {
			getNoOfLines();
			checkiffileexists();
			ofstream file;
			file.open(filename.c_str(), ios::app);
			cout << "No. of Lines: ";
			cin >> writelines;
			cin.ignore(1,'\n');
			for(i = 0; i < writelines; i++) {
				cout << "Line " << i + 1 << ": ";
				getline(cin, input);
				file << input;
				file << "\n";
			}
			file.close();
		}
		void createfile() {
			ifstream file(filename.c_str());
			if(file.good() == 1) {
				cout << "The file already exists\n\e[1mWould you like to overwrite the file\e[0m? (y/n)" << endl;
				cin >> input;
				if(input == "y") {
					ofstream file;
					file.open(filename.c_str());
					file << endl;
					file.close();
					cerr << "\e[1mSuccess\e[0m: File created" << endl;
				} else {
					cout << "\e[1mWARNING\e[0m: File creation process halted!\n" << endl;
				}
			} else {
				ofstream file;
				file.open(filename.c_str());
				file << endl;
				file.close();
				cerr << "Success: File created" << endl;
			}
		}
		void renamefile() {
			cout << "\e[1mOld filename + directory\e[0m: ";
			cin.ignore(1,'\n');
			getline(cin, oldname);
			cout << "\e[1mNew filename + directory\e[0m: ";
			getline(cin, filename);
			result = rename(oldname.c_str(), filename.c_str());
			if(result == 0) {
				cout << "File was successfully renamed!";
			} else {
				perror("openDATA Error");
			}
		}
		void deletefile() {
			inputfilename();
			if(remove(filename.c_str()) != 0) {
				perror("\e[1mopenDATA Error\e[0m");
			} else {
				cout << "File successfully deleted!" << endl;
			}
		}
		void overwritefile() {
			inputfilename();
			ifstream file;
			file.open(filename.c_str());
			if(remove(filename.c_str()) != 0) {
				perror("openDATA Error");
				file.close();
			} else {
				file.close();
				ofstream file;
				file.open(filename.c_str());
				file << endl;
				file.close();
				cout << "File successfully overwritten!" << endl;
			}
			file.close();
			cout << endl;
		}
		void findfilesize() {
			cout << "\e[1mPath to file + filename\e[0m: ";
			cin.ignore(1,'\n');
			getline(cin, filename);
			ifstream file(filename.c_str(), ios::binary | ios::ate);
			cout << "\e[1mFile size\e[0m: " << file.tellg() << endl;
		}
		void directoryview() {
			cout << "\e[1mDirectory\e[0m: ";
			cin.ignore(1,'\n');
			getline(cin, directory);
			cout << endl;
			system(("dir "+directory+"").c_str());
		}
	private:
		void getNoOfLines() {
			ifstream file(filename.c_str());
			while(getline(file, line)) {
				++lines;
			}
		}
		void commandLibrary() {
			if(command == "exit") {
				cout << "\e[1mThank you for using openDATA Build 100\n\e[0m" << endl;
				exit(0);
			} else if(command == "read") {
				inputfilename();
				readfile();
			} else if(command == "write") {
				inputfilename();
				writefile();
			} else if(command == "clear") {
				system("cmd /c cls");
			} else if(command == "help") {
				cout << "\n\e[1mopenDATA Build 100 Command List\e[0m\nabout: gives more information about openDATA Build 100\nclear: clear the screen\ncreate: make a new file\ndelete: delete a file\ndirectoryview: view contents of directory\nexit: quit openDATA\nfilesize: gives size of file in bytes\noverwrite: delete data from file\nread: read a file\nrename: rename a file\nwrite: write to a file\n" << endl;
			} else if(command == "create") {
				inputfilename();
				createfile();
			} else if(command == "rename") {
				renamefile();
			} else if(command == "delete") {
				deletefile();
			} else if(command == "overwrite") {
				overwritefile();
			} else if(command == "about") {
				system("cmd /c cls");
				cout << "openDATA Build 100 Build 100 5/12/17 for Windows\nWritten by jaxxmelbourne27\n\n\e[1mWhat's New in Build 100\e[0m\n" << endl;
				cout << "\e[1mDirectory View\e[0m: The directory view function has been added to see the files located in a specific directory. \n" << endl;
				cout << "\e[1mRename Bug Fix\e[0m: The rename function was rewritten to remove a bug which would not allow the user to rename the file With an error saying that the file and directory was not found.\n" << endl;
			} else if(command == "filesize") {
				findfilesize();
			} else if(command == "directoryview") {
				directoryview();
			} else {
				cout << "\e[1mError: Command not recognised\e[0m" << endl;
			}
		}
		void checkiffileexists() {
			ifstream file(filename.c_str());
			if(file.good() == 0) {
				cout << "The file doesn't exist\n\e[1mWould you like to create the file\e[0m? (y/n)" << endl;
				cin >> input;
				if(input == "y") {
					ofstream file;
					file.open(filename.c_str());
					file << endl;
					file.close();
					cerr << "\e[1mSuccess\e[0m: File created" << endl;
				}
			}
		}
};
