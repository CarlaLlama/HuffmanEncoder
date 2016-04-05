/**
*.cpp Huffencode File - HuffmanTree and HuffmanNode files
* Carla Wilby 31/03/2016
*/

#include "huffencode.h"
#include <iostream>
#include <memory>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <vector>
#include <unordered_map>

using namespace std;



HuffmanTree::HuffmanTree(){
	//one tree or many trees?
	//std::shared_ptr<HuffmanNode> leftnode;
	//std::shared_ptr<HuffmanNode> rightnode;
	//std::shared_ptr<HuffmanNode> rootnode;
}

HuffmanTree::~HuffmanTree(){
	//root node set to nullptr
}
	
//method to build tree
void HuffmanTree::buildTree(string & letters){
	//one tree with lots of baby trees?
	//what do I call big tree then?
}
	
//method to compress data
void HuffmanTree::compressData(void){

}

HuffmanNode::HuffmanNode(char l, int f){
	letter = l;
	freq = f;
}

HuffmanNode::~HuffmanNode(){

}