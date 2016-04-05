/**
*.h Header file
* Carla Wilby 31/03/2016
*/

#ifndef HUFFENCODE_H
#define HUFFENCODE_H
#include <iostream>
#include <cstdlib>
#include <vector>
#include <iostream>
#include <sstream>
#include <unordered_map>


class HuffmanTree
{
private:
	

public:
	//IMPLEMENT
	//default constructor
	//move constructor
	//copy constructor
	//destructor
	//copy assignment operator
	//move assignment operator

	HuffmanTree();
	~HuffmanTree();
	
	//method to build tree
	void buildTree(std::string & letters);

	//method to compress data
	void compressData(void);
};

class HuffmanNode
{
private:
	char letter;
	int freq;

public:

	HuffmanNode(char l, int f);
	~HuffmanNode();
};



#endif
