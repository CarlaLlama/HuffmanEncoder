/**
*.cpp Huffman Encoding Driver File
* Carla Wilby 31/03/2016
*/
#include "huffencode.h"

using namespace std;

int main(int argc, char* argv[])
{
	string inputFile;
	string outputFile;

	// Preliminary input checking
	if(argc < 2){
		cout << "Incorrect program entry." << endl;
		cout << "huffencode <inputFile> <output file prefix>" << endl;
		return 0;
	}

	inputFile = string(argv[1]);
	outputFile = string(argv[2]);

    // Make new huffman tree 
    WLBCAR002::HuffmanTree huffpuff;

    // Read contents of file, add characters to map cnt
 	unordered_map<char, int> cnt = huffpuff.readData(inputFile, outputFile);
	
	// Build huffman tree from map cnt
	huffpuff.buildTree(cnt);

	// Generate code table based on the huffman tree	
	huffpuff.makeCodeTable(huffpuff.getRoot(), "");

	// Write code representation of input file to bit buffer
	huffpuff.compressData();
	
	// Print bit buffer out to file
	huffpuff.printToFile();

	return 0;

}