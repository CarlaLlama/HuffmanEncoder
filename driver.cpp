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

using namespace std;


int main(int argc, char* argv[])
{
	string inputFile;
	string outputFile;

	if(argc < 2){
		cout << "Incorrect program entry." << endl;
		cout << "huffencode <inputFile> <output file>" << endl;
		return 0;
	}

	inputFile = string(argv[1]);
	outputFile = string(argv[2]);

	//Read in contents from input file
	ifstream ifs(inputFile.c_str());

	if(!ifs){
		cout << "File not found." << endl;
		cout << "Please ensure you have entered the correct name of the input file" << endl;
		return 0;
	}

	//read in line by line, add to u
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

	for( const auto& n : cnt ) {
        std::cout << "Key:[" << n.first << "] Value:[" << n.second << "]\n";
    }
 

	//make tree, pass in counts
	//HuffmanTree huffpuff = new HuffmanTree;
	//huffpuff.buildTree(cnt);

	return 0;
}