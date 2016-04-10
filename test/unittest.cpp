#define CATCH_CONFIG_MAIN
#include "unittest.h"
#include "unittest.h"
#include <memory>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <queue>
#include <cstdlib>


namespace WLBCAR002{
using namespace std;
TEST_CASE("Building tree", "[HuffmanTree]"){
	SECTION("Priority queue implementation"){
		priority_queue<shared_ptr<HuffmanNode>, vector<shared_ptr<HuffmanNode>>, Compare> pq;

		shared_ptr<HuffmanNode> n1(new HuffmanNode('h', 5));
		pq.push(n1);
		shared_ptr<HuffmanNode> n2(new HuffmanNode('g', 9));
		pq.push(n2);
		shared_ptr<HuffmanNode> n3(new HuffmanNode('v', 41));
		pq.push(n3);
		shared_ptr<HuffmanNode> n4(new HuffmanNode('c', 12));
		pq.push(n4);
		shared_ptr<HuffmanNode> n5(new HuffmanNode('b', 6));
		pq.push(n5);

		// Test priority queue comparison
		shared_ptr<HuffmanNode> top = pq.top();
		REQUIRE((*top).getFreq() == 5);
		REQUIRE((*top).getLetter() == 'h');

	}

	SECTION("Priority queue insertion from unordered map"){
		unordered_map<char, int> testmap;
		testmap.insert(std::make_pair('i', 35));
		testmap.insert(std::make_pair('a', 1));
		testmap.insert(std::make_pair('j', 4));

		priority_queue<shared_ptr<HuffmanNode>, vector<shared_ptr<HuffmanNode>>, Compare> pq;

		for( const auto& n : testmap ) {
			shared_ptr<HuffmanNode> currentNode(new HuffmanNode(n.first, n.second));
			pq.push(currentNode);
	    }

	    // Test priority queue comparison
		shared_ptr<HuffmanNode> top = pq.top();
		REQUIRE((*top).getFreq() == 1);
		REQUIRE((*top).getLetter() == 'a');

	}

	SECTION("Tree building"){
		unordered_map<char, int> testmap;
		testmap.insert(std::make_pair('i', 35));
		testmap.insert(std::make_pair('a', 1));
		testmap.insert(std::make_pair('j', 4));

		HuffmanTree huff;
		huff.buildTree(testmap);

		// Check count of root
		shared_ptr<HuffmanNode> root = huff.getRoot();
		REQUIRE((*root).getFreq() == 40);

		// Check children are in the right place
		REQUIRE((*((*root).getRight())).getFreq() == 35);
		REQUIRE((*((*root).getLeft())).getFreq() == 5);
		REQUIRE((*(*((*root).getLeft())).getRight()).getFreq() == 4);
		REQUIRE((*(*((*root).getLeft())).getLeft()).getFreq() == 1);
	}
}

TEST_CASE("Making code table", "[HuffmanTree]"){
		unordered_map<char, int> testmap;
		testmap.insert(std::make_pair('i', 5));
		testmap.insert(std::make_pair('a', 1));
		testmap.insert(std::make_pair('j', 4));

		HuffmanTree huff;
		huff.buildTree(testmap);
		huff.makeCodeTable(huff.getRoot(), "");

		// Check entries in code table
		REQUIRE(huff.codeTable.at('i') == "1");
		REQUIRE(huff.codeTable.at('a') == "00");
		REQUIRE(huff.codeTable.at('j') == "01");
}

TEST_CASE("Making new node", "[HuffmanNode]"){
	shared_ptr<HuffmanNode> testNode(new HuffmanNode('f', 43));
	REQUIRE((*testNode).getFreq() == 43);
	REQUIRE((*testNode).getLetter() == 'f');
}

TEST_CASE("Getting and setting frequency", "[HuffmanNode]"){
	shared_ptr<HuffmanNode> testNode(new HuffmanNode('a', 4));
	REQUIRE((*testNode).getFreq() == 4);
	REQUIRE((*testNode).getLetter() == 'a');
	(*testNode).setFreq(5);
	REQUIRE((*testNode).getFreq() == 5);

}

TEST_CASE("Getting and setting left child node", "[HuffmanNode]"){
	shared_ptr<HuffmanNode> testNode(new HuffmanNode('a', 4));
	shared_ptr<HuffmanNode> t2(new HuffmanNode('b', 2));
	(*testNode).setLeft(t2);
	REQUIRE((*((*testNode).getLeft())).getFreq() == 2);
}

TEST_CASE("Getting and setting right child node", "[HuffmanNode]"){
	shared_ptr<HuffmanNode> testNode(new HuffmanNode('a', 4));
	shared_ptr<HuffmanNode> t2(new HuffmanNode('b', 5));
	(*testNode).setRight(t2);
	REQUIRE((*((*testNode).getRight())).getFreq() == 5);
}

}