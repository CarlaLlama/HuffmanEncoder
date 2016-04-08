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

#include <memory>
#include <unordered_map>

class HuffmanNode
{
private:
	char letter;
	int freq;
	std::shared_ptr<HuffmanNode> left = nullptr;
	std::shared_ptr<HuffmanNode> right = nullptr;

public:

	HuffmanNode(char l, int f);
	~HuffmanNode();

	int getFreq(void) const;

	void setFreq(int f);

	char getLetter(void) const;

	void setLeft(std::shared_ptr<HuffmanNode> l);

	void setRight(std::shared_ptr<HuffmanNode> r);	

	std::shared_ptr<HuffmanNode> getLeft(void) const;

	std::shared_ptr<HuffmanNode> getRight(void) const;	

	bool operator<(const HuffmanNode& b) const;
};


class HuffmanTree
{
private:
	std::string inFile;
	std::string outFile;
	std::string bitBuffer;
	std::shared_ptr<HuffmanNode> root = nullptr;

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

	void readData(std::string inputFile, std::string outputFile);
	
	//method to build tree
	void buildTree(std::unordered_map<char, int> & cnt);

	void makeCodeTable(std::shared_ptr<HuffmanNode> currentNode, std::string bits);

	void printToFile(void);

	void setRoot(std::shared_ptr<HuffmanNode> r);

	std::shared_ptr<HuffmanNode> getRoot(void) const;

	std::unordered_map<char, std::string> codeTable;

	//method to compress data
	void compressData(void);
};

struct Compare
{

  bool operator()(const std::shared_ptr<HuffmanNode>& lhs, const std::shared_ptr<HuffmanNode>& rhs) const;
};


#endif
