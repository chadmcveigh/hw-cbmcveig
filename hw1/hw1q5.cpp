#include <iostream>
#include <cstdlib>
#include <cstring>
#include <fstream>

using namespace std;

int main(int argc, char * argv[])
{
	int words = 0;

	// do .open for the ifile.
	ifstream ifile;

	ifile.open(argv[1]);

	ifile >> words;

	cout << "word: " << words << endl;

	string *data = new string[words];

	for(int i = 0; i < words; i++){
		ifile >> data[i];
	}

	for(int i = words - 1; i >= 0; i--){
		cout << data[i] << endl;
	}

	delete [] data;



}