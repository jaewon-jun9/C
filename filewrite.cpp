#include <fstream>
#include <iostream>

using namespace std;

int main()
{
	string filePath = "test.txt";

	// write File
	ofstream writeFile(filePath.data());
	if( writeFile.is_open() ){
		writeFile << "Hello World!\n";
		writeFile << "This is C++ File Contents.\n";
		writeFile.close();
	}

	// read File
	ifstream openFile(filePath.data());
	if( openFile.is_open() ){
		string line;
		while(getline(openFile, line)){
			cout << line << endl;
		}
		openFile.close();
	}

	return 0;
}
