/**
*.cpp Huffencode File - HuffmanTree and HuffmanNode files
* Carla Wilby 31/03/2016
*/

#include "huffencode.h"

namespace WLBCAR002{

	using namespace std;

	HuffmanTree::~HuffmanTree(){
		root = nullptr;
	}

	// Read contents of file, add characters to map cnt
	unordered_map<char, int> HuffmanTree::readData(string inputFile, string outputFile){
		inFile = inputFile;
		outFile = outputFile;
		unordered_map<char, int> cnt;

		// Read in contents from input file
		ifstream ifs(inFile.c_str());

		// File checking
		if(!ifs){
			cout << "File not found." << endl;
			cout << "Please ensure you have entered the correct name of the input file" << endl;
			return cnt;
		}

		string line;
		// Read in line by line, add to unordered map
		while(getline(ifs, line)){
			for(string::size_type i = 0; i < line.size(); ++i){
				unordered_map<char, int>::const_iterator letter= cnt.find(line[i]);
				if(letter == cnt.end()){
					// Add to unordered_map
					cnt.insert(std::make_pair(line[i], 1));
				}else{
					// If already inside map, increment counter
					int count = letter->second;
					count++;
					cnt[line[i]] = count;
				}
			}
		}
		ifs.close();
		return cnt;
	}
		
	// Method to make priority queue with HuffmanNodes
	void HuffmanTree::buildTree(unordered_map<char, int> & cnt){
		priority_queue<shared_ptr<HuffmanNode>, vector<shared_ptr<HuffmanNode>>, Compare> pq;

		// Iterate through map, creating shared ptr to a new Huffman node for each character
		// Add each new node to priority queue
		for( const auto& n : cnt ) {
			shared_ptr<HuffmanNode> currentNode(new HuffmanNode(n.first, n.second));
			pq.push(currentNode);
	    }

	    // Make left and right children based on nodes with smallest frequency
	    // Iterate to make tree
	    while(!pq.empty()){
	    	if(pq.size() == 1){
				// Make root
	    		root = pq.top();
	    		pq.pop();
	    	}else{
		    	shared_ptr<HuffmanNode> parent(new HuffmanNode('\0',0));
		    	(*parent).setLeft(pq.top());
		    	pq.pop();
		    	(*parent).setRight(pq.top());
				pq.pop();

				// Calculate parent frequency
				int freq = (*(*parent).getLeft()).getFreq() + (*(*parent).getRight()).getFreq();
				(*parent).setFreq(freq);

				// Put new parent node back into priority queue
				pq.push(parent);
			}
		}
	}

	// Generate code table based on the huffman tree
	void HuffmanTree::makeCodeTable(std::shared_ptr<HuffmanNode> currentNode, string bits){
		if((*currentNode).getLeft() != nullptr){
			makeCodeTable((currentNode->getLeft()), (bits + "0"));
		}
		// When Node with character is reached, add its bits path to code table
		if((*currentNode).getLetter()!='\0'){
			codeTable.insert(std::make_pair((*currentNode).getLetter(), bits));
			bits = "";
		}
		if((*currentNode).getRight() != nullptr){
			makeCodeTable((currentNode->getRight()), (bits + "1"));
		}
	}
		
	// Write code representation of input file to bit buffer
	void HuffmanTree::compressData(void){
		// Read in line by line, add character representation to bit buffer
		ifstream ifs(inFile.c_str());
		string line;
		while(getline(ifs, line)){
			for(std::string::size_type i = 0; i < line.size(); ++i){
				std::unordered_map<char,string>::const_iterator letter = codeTable.find(line[i]);
				bitBuffer += (*letter).second;
			}
		}
		ifs.close();
	}

	// Print bit buffer out to file
	void HuffmanTree::printToFile(void){
		// Print contents of codeTable to output header file
		string out = outFile + ".hdr";
	 	ofstream offile(out.c_str());
	 	offile << codeTable.size() << endl;
		for( const auto& n : codeTable) {
			stringstream ss;
			string ch;
			ss << n.first;
			ss >> ch;
			string line = "Character:[" + ch + "] Code:[" + n.second + "]";
	        offile << line << endl;
	    }

	    // Print bit buffer to bit bin file
	    string bout = outFile + ".bin";
	    ofstream ofile(bout.c_str());
	    string buff = bitBuffer.c_str();
	    ofile << buff;
	}

	std::shared_ptr<HuffmanNode> HuffmanTree::getRoot(void) const{
		return root;
	}

/* HUFFMAN NODE CLASS IMPLEMENTATION */

	HuffmanNode::HuffmanNode(char l, int f){
		letter = l;
		freq = f;
	}

	HuffmanNode::~HuffmanNode(){
	}

	// Operator overloading of < for HuffmanNodes
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

}