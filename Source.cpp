#include<iostream>
#include<string>
#include<fstream>
#include<algorithm>

#include "Options.h"

using namespace std;

bool stringFound(string, string);
bool stringFound(string, string, const Options&);
void noArgsSearch();
void twoArgsSearch(string, string);
void threeArgsSearch(string, string, const Options&);



int main(int argc, char* argv[]) {

	switch (argc) {
	case 1: {
		// Starting program without command line arguments.

		noArgsSearch();

		break;
	}
	case 3: {
		// Starting program with 2 command line arguments. Arguments passed to function.

		string stringKey = argv[1], source = argv[2];
		twoArgsSearch(stringKey, source);

		break;
	}
	case 4: {
		// Starting program with 3 command line arguments. Options, key string, file name.

		// If first argument in command line starts with chars "-o", Construct Options object based on 
		// command line argument. Pass command line arguments to function.
		string stringKey = argv[2], source = argv[3];

		try {
			if (argv[1][0] == '-' && argv[1][1] == 'o') {
				Options OptionArgs{ argv[1] };

				threeArgsSearch(stringKey, source, OptionArgs);

			}
			else {
				cout << "User first argument not valid\n";
			}
		}
		catch (int errorNumber) {
			cout << "An exception occurred. Exception Nr. " << errorNumber << endl;
			cout << "Could not find the file :" << '"' << source << '"' << endl;
		}




		break;
	}

	default:
		cout << "Illegal amount of arguments!\n";
	}


	return 0;
}
bool stringFound(string source, string key) {


	size_t found = source.find(key);
	if (found != string::npos) {
		return true;
	}
	else {
		return false;
	}
}
bool stringFound(string source, string key, const Options& OptionArgs) {

	bool result;

	if (OptionArgs.ignoreCase) {
		transform(source.begin(), source.end(), source.begin(), ::toupper);
		transform(key.begin(), key.end(), key.begin(), ::toupper);
	}

	size_t found = source.find(key);
	if (found != string::npos) {
		result = true;

		if (OptionArgs.reverseSearch)
			result = false;
	}
	else {
		result = false;

		if (OptionArgs.reverseSearch)
			result = true;
	}
	return result;
}
void noArgsSearch() {

	// Ask from user two strings. Source string and key string what to search from source.
	string stringSource, stringKey;

	cout << "Give a string from which to search for: ";
	getline(cin, stringSource);
	cout << "Give search string: ";
	getline(cin, stringKey);

	// If Source string contains key string exactly, found get value which is index position where key found.
	size_t found = stringSource.find(stringKey);

	// If found have any value then key string found. Print results to user.
	if (found != string::npos) {
		cout << '"' + stringKey + '"' << " found in " << '"' + stringSource + '"'
			<< " in position " << found << endl;
	}
	else {
		cout << '"' + stringKey + '"' << " NOT found in " << '"' + stringSource + '"' << endl;
	}
}
void twoArgsSearch(string stringKey, string source) {

	// Create and open infile object which filename user gave at command line.
	ifstream infile;
	infile.open(source);


	if (!infile) {
		cerr << "Failed to open .txt file";
		return;
	}

	// Print every line from source file which contains key string. User gave key string at command line.
	// stringFound return true if source line include exactly string key.
	string line;
	while (getline(infile, line)) {
		if (stringFound(line, stringKey)) {
			cout << line << endl;
		}
	}
	infile.close();
}
void threeArgsSearch(string stringKey, string source, const Options& OptionArgs) {


	// Create and open infile object which filename user gave at command line.
	ifstream infile;
	infile.open(source);

	if (!infile) {
		throw 1;
	}

	int lineCount{ 1 }, occurenceCount{ 0 };
	string line;

	while (getline(infile, line)) {

		if (stringFound(line, stringKey, OptionArgs)) {
			if (OptionArgs.lineNumbering) {
				cout << lineCount << ": ";
			}
			cout << line << endl;

			occurenceCount++;
		}
		lineCount++;
	}

	if (OptionArgs.occurences) {
		if (!OptionArgs.reverseSearch) {
			cout << "Occurrences of lines containing " << '"' << stringKey << '"' << ": " << occurenceCount << endl;
		}
		else {
			cout << "Occurences of lines NOT containing " << '"' << stringKey << '"' << ": " << occurenceCount << endl;
		}
	}
	infile.close();
}