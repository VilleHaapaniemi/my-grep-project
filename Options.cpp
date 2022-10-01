#include "Options.h"
#include<string>
#include<cstring>
#include<iostream>

// Constructor get pointer to c string as parameter. String starts with command "-o" and after that every
// char found change option value true.

Options::Options(char* argv)
	: lineNumbering{ false }, occurences{ false }, ignoreCase{ false }, reverseSearch{ false } {


	for (size_t i = 2; i < strlen(argv); i++) {
		if (argv[i] == 'l')
			lineNumbering = true;
		if (argv[i] == 'o')
			occurences = true;
		if (argv[i] == 'i')
			ignoreCase = true;
		if (argv[i] == 'r')
			reverseSearch = true;
	}
}