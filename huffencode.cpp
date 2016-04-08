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
#include <memory>
#include <queue>


using namespace std;



HuffmanTree::HuffmanTree(){
	//one tree or many trees?
	//std::shared_ptr<HuffmanNode> leftnode;
	//std::shared_ptr<HuffmanNode> rightnode;
	//std::shared_ptr<HuffmanNode> rootnode;
}

HuffmanTree::~HuffmanTree(){
	root = nullptr;
}

void HuffmanTree::readData(string inputFile, string outputFile){
	inFile = inputFile;
	outFile = outputFile;

	//Read in contents from input file
	ifstream ifs(inFile.c_str());

	if(!ifs){
		cout << "File not found." << endl;
		cout << "Please ensure you have entered the correct name of the input file" << endl;
		return;
	}

	//read in line by line, add to unordered map
	string line;
	std::unordered_map<char, int> cnt;

	while(getline(ifs, line)){
		for(std::string::size_type i = 0; i < line.size(); ++i){
			std::unordered_map<char, int>::const_iterator letter= cnt.find(line[i]);
			if(letter == cnt.end()){
				//add to unordered_map
				cnt.insert(std::make_pair(line[i], 1));
			}else{
				//if inside increment counter
				int count = letter->second;
				count++;
				cnt[line[i]] = count;
			}
		}
	}
	ifs.close();
	buildTree(cnt);
}
	
//method to make priority queue with HuffmanNodes
void HuffmanTree::buildTree(unordered_map<char, int> & cnt){
	HuffmanTree tree;
	priority_queue<shared_ptr<HuffmanNode>, vector<shared_ptr<HuffmanNode>>, Compare> pq;

	for( const auto& n : cnt ) {
		shared_ptr<HuffmanNode> currentNode(new HuffmanNode(n.first, n.second));
		pq.push(currentNode);
        //std::cout << "Key:[" << n.first << "] Value:[" << n.second << "]\n";
    }

    while(!pq.empty()){
    	if(pq.size() == 1){
			//make root
    		tree.setRoot(pq.top());
    		pq.pop();
    	}else{
	    	shared_ptr<HuffmanNode> parent(new HuffmanNode('\0',0));
	    	cout << "LEFT :" << (*pq.top()).getLetter() << endl;
	    	(*parent).setLeft(pq.top());
	    	pq.pop();
	    	cout << "RIIGHT :" << (*pq.top()).getLetter() << endl;
	    	(*parent).setRight(pq.top());
			pq.pop();

			//calculate parent frequency
			int freq = (*(*parent).getLeft()).getFreq() + (*(*parent).getRight()).getFreq();
			(*parent).setFreq(freq);
			pq.push(parent);
		}
	}
	makeCodeTable(tree.getRoot(), "");

	cout << "TABLE" << endl;
	for( const auto& n : codeTable) {
		//shared_ptr<HuffmanNode> currentNode(new HuffmanNode(n.first, n.second));
		//pq.push(currentNode);
        std::cout << "Key:[" << n.first << "] Value:[" << n.second << "]\n";
    }

    compressData();


}

void HuffmanTree::makeCodeTable(std::shared_ptr<HuffmanNode> currentNode, string bits){
	if((*currentNode).getLeft() != nullptr){
		makeCodeTable((currentNode->getLeft()), (bits + "0"));
	}
	if((*currentNode).getLetter()!='\0'){
		codeTable.insert(std::make_pair((*currentNode).getLetter(), bits));
		bits = "";
	}
	if((*currentNode).getRight() != nullptr){
		makeCodeTable((currentNode->getRight()), (bits + "1"));
	}
}
	
//method to compress data
void HuffmanTree::compressData(void){
	//read in line by line, add character representation to bit buffer
	ifstream ifs(inFile.c_str());
	string line;
	while(getline(ifs, line)){
		for(std::string::size_type i = 0; i < line.size(); ++i){
			std::unordered_map<char,string>::const_iterator letter = codeTable.find(line[i]);
			bitBuffer += (*letter).second;
		}
		cout << bitBuffer << endl;
	}
	ifs.close();
	printToFile();
}

void HuffmanTree::printToFile(void){
	//print contents of codeTable to output header file
	string out = outFile + ".hdr";
 	ofstream offile(out.c_str());
 	offile << codeTable.size() << endl;
	for( const auto& n : codeTable) {
		//shared_ptr<HuffmanNode> currentNode(new HuffmanNode(n.first, n.second));
		//pq.push(currentNode);
		stringstream ss;
		string ch;
		ss << n.first;
		ss >> ch;
		string line = "Character:[" + ch + "] Code:[" + n.second + "]";
        offile << line << endl;
    }

    //print bit buffer to bit file
    string bout = outFile + ".bin";
    ofstream ofile(bout.c_str());
    string buff = bitBuffer.c_str();
    ofile << buff;

}

void HuffmanTree::setRoot(std::shared_ptr<HuffmanNode> r){
	root = move(r);
}

std::shared_ptr<HuffmanNode> HuffmanTree::getRoot(void) const{
	return root;
}

HuffmanNode::HuffmanNode(char l, int f){
	letter = l;
	freq = f;
}

HuffmanNode::~HuffmanNode(){
}

bool HuffmanNode::operator<(const HuffmanNode& b) const
{
	if(this->freq < b.freq){
		return true;
	}else{
		return false;
	}
}

int HuffmanNode::getFreq(void) const{
	return freq;
}

void HuffmanNode::setFreq(int f){
	freq = f;
}

char HuffmanNode::getLetter(void) const{
	return letter;
}

void HuffmanNode::setLeft(std::shared_ptr<HuffmanNode> l){
	left = move(l);
}

void HuffmanNode::setRight(std::shared_ptr<HuffmanNode> r){
	right = move(r);
}

std::shared_ptr<HuffmanNode> HuffmanNode::getLeft(void) const{
	return left;
}

std::shared_ptr<HuffmanNode> HuffmanNode::getRight(void) const{
	return right;
}

bool Compare::operator()(const shared_ptr<HuffmanNode>& lhs, const shared_ptr<HuffmanNode>& rhs) const
{
	return !((*lhs).getFreq() < (*rhs).getFreq());
}

