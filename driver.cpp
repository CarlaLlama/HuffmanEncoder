/**
*.cpp Huffman Encoding Driver File
* Carla Wilby 31/03/2016
*/
#include "huffencode.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <queue>
#include <memory>

using namespace std;


int main(int argc, char* argv[])
{
	string inputFile;
	string outputFile;

	if(argc < 2){
		cout << "Incorrect program entry." << endl;
		cout << "huffencode <inputFile> <output file prefix>" << endl;
		return 0;
	}

	inputFile = string(argv[1]);
	outputFile = string(argv[2]);

    //Make new huffman tree
    HuffmanTree huffpuff;
 	huffpuff.readData(inputFile, outputFile);

	return 0;
}