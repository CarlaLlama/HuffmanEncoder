#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "../huffencode.h"
#include <memory>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <queue>
#include <cstdlib>


using namespace std;

TEST_CASE("asrfgflarejklfsda", "[huffencode]"){
	SECTION("priority quieue"){

		priority_queue<shared_ptr<HuffmanNode>, std::vector<shared_ptr<HuffmanNode>>, Compare> pq;
		pq.push(shared_ptr<HuffmanNode> currentNode(new HuffmanNode('d', 4)));
		pq.push(shared_ptr<HuffmanNode> currentNode(new HuffmanNode('j', 2)));

		shared_ptr<HuffmanNode> top = pq.top();

		REQUIRE(top.getFreq() == 2);
	}
}
