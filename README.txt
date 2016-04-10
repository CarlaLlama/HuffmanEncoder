HUFFMAN ENCODER
---------------

To compile this project:
	Extract project to desired directory
	cd into project directory
	run:
		$ make

To run this project:
	Ensure it has been compiled correctly
	cd into project directory
	run:
		$ ./huffencode <input file name> <output file prefix>

To clean project:
	run:
		$ make clean

COMMAND LINE ARGUMENTS
----------------------

huffencode : name of executable
<input file name> : name of text files to be encoded
<output file prefix> : prefix of encoded output files

HELP
----

1. If this directory is not included in the project path, ./ will have to be used before the executable name (ie ./huffencode)
2. The output will result in a header file (<name>.hdr) and binary encoding output (<name>.bin)
3. Testing files are contained in the testing subdirectory (./test). Running make in this directory will generate them.

DIRECTORY STRUCTURE
-------------------

Here is an example of the working directory structure:

/huffencode
	/driver.cpp
	/huffencode.cpp
	/huffencode.h
	/Makefile
	/README.txt
	/.gitignore
	/test
		/unittest.cpp
		/unittest.h
		/catch.hpp
		/Makefile

FILE STRUCTURE
--------------

Makefile:
	Used to correctly compile source files.
driver.cpp:
	Source file containing main() method, called at start of project.
	Reads in arguments from user.
huffencode.h:
	Header file containing HuffmanTree and HuffmanNode class declaration.
huffencode.cpp:
	Source file containing tree and encoding implementation.

OUTPUT FILES
------------

<output file prefix>.hdr:
	This header file contains:
		First line: the number of characters encoded in the code table
		Following lines: the characters and their associated encoded bit strings

<output file prefix>.bin:
	This binary file contains:
		The bit string equivalent of the input file string using the code table

MAINTAINERS
-----------

Current Maintainers:
* Carla Wilby (carlallama) - https://github.com/CarlaLlama