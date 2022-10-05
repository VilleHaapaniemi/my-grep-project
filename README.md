# **my-grep-project :telescope::spiral_notepad:**

## Description

The grep filter searches a file for a particular pattern of characters, and displays all lines that contain that pattern.



## How to use

| Arguments | Description |
| ------ | ----------- |
|0       |Compare two strings given by user.|
|2       |Compare user given string and text file.|
|3       |Same as 2 arguments including options to manipulate output. |

## Example


    // 3 arguments. (Options must begin with -o<option_letters>
    ./mygrep -oli <key_word> <file_name>

## Docker branch


    
    docker build -t mygrep .
    docker run --rm -it -e options=<options> -e keyword=<keyword> -e filename=<filename> mygrep

### Known bugs
- Docker version only working by 3 args
## Options

- l = Print line numbers
- i = Ignore case.
- r = Reverse search.
- o = Print occurrences count of lines.
