/**
*.h Header file
* Carla Wilby 31/03/2016
*/

#ifndef HUFFENCODE_H
#define HUFFENCODE_H
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <memory>
#include <queue>

namespace WLBCAR002{

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
		HuffmanTree(void) = default;

		~HuffmanTree();

		HuffmanTree(const HuffmanTree & rhs) : inFile(rhs.inFile), outFile(rhs.outFile), bitBuffer(rhs.bitBuffer), root(rhs.root){};
		
		HuffmanTree(HuffmanTree && rhs) : inFile(std::move(rhs.inFile)), outFile(std::move(rhs.outFile)), bitBuffer(std::move(rhs.bitBuffer)), root(std::move(rhs.root)){ (rhs).root = nullptr; };

		HuffmanTree & operator=(const HuffmanTree & rhs){
			if(this != &rhs){
				inFile = rhs.inFile;
				outFile = rhs.outFile;
				bitBuffer = rhs.bitBuffer;
				root = rhs.root;
			}
			return *this;
		}

		HuffmanTree & operator=(HuffmanTree && rhs){
			if(this != &rhs){
				inFile = std::move(rhs.inFile);
				outFile = std::move(rhs.outFile);
				bitBuffer = std::move(rhs.bitBuffer);
				root = rhs.root;
				rhs.root = nullptr;
			}
			return *this;
		}

		std::unordered_map<char, int> readData(std::string inputFile, std::string outputFile);
		
		void buildTree(std::unordered_map<char, int> & cnt);

		void makeCodeTable(std::shared_ptr<HuffmanNode> currentNode, std::string bits);

		void printToFile(void);

		std::shared_ptr<HuffmanNode> getRoot(void) const;

		std::unordered_map<char, std::string> codeTable;

		void compressData(void);
	};

	struct Compare
	{

	  bool operator()(const std::shared_ptr<HuffmanNode>& lhs, const std::shared_ptr<HuffmanNode>& rhs) const;
	};

}
#endif
