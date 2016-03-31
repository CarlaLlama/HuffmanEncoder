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
	std::shared_ptr<HuffmanNode> leftnode;
	std::shared_ptr<HuffmanNode> rightnode;
	std::shared_ptr<HuffmanNode> rootnode;

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
	void buildTree(unordered_map & letters);

	//method to compress data
	void compressData(void);
};

class HuffmanNode
{
private:

public:

	HuffmanNode();
	~HuffmanNode();
	int volNumberImages(void);
};



#endif
