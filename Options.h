#pragma once
class Options
{
public:
	bool lineNumbering,
		occurences,
		ignoreCase,
		reverseSearch;

	// Constructor takes pointer to char. Pointer points to user input for argv options chars.
	Options(char*);
};