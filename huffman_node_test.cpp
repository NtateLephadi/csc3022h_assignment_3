#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "huffman_node.h"
#include <memory>


TEST_CASE( "Huffman node constructor test", "[huffman_node()]" ) {
    huffman_node h = huffman_node();
    REQUIRE(h.getLetter() == 0);
    REQUIRE(h.getFrequency() == 0);	
    REQUIRE(h.getLeft() == nullptr);
    REQUIRE(h.getRight() == nullptr);
}

TEST_CASE( "Huffman node constructor test", "[huffman_node(char, int, const shared_ptr<huffman_node>, const shared_ptr<huffman_node>)]"){
	shared_ptr<huffman_node> left = new huffman_node('a', 1, nullptr, nullptr);
	shared_ptr<huffman_node> right = new huffman_node('b', 2, nullptr, nullptr);
	huffman_node h = new huffman_node('c', 3, left, right);
}
