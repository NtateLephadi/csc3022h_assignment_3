#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "huffman_node.h"
#include <memory>

using namespace std;


TEST_CASE( "Huffman node default constructor test", "[huffman_node()]" ) {
    huffman_node h = huffman_node();
    REQUIRE(h.getLetter() == 0);
    REQUIRE(h.getFrequency() == 0);	
    REQUIRE(h.getLeft() == nullptr);
    REQUIRE(h.getRight() == nullptr);
}

TEST_CASE( "Huffman node custom constructor test", "[huffman_node(char, int, const shared_ptr<huffman_node>, const shared_ptr<huffman_node>)]"){
	shared_ptr<huffman_node> left(new huffman_node('a', 1, nullptr, nullptr));
	shared_ptr<huffman_node> right(new huffman_node('b', 2, nullptr, nullptr));
	huffman_node h = huffman_node('c', 3, left, right);
	REQUIRE(h.getLetter() == 'c');
    REQUIRE(h.getFrequency() == 3);	
    REQUIRE(h.getLeft() == left);
    REQUIRE(h.getRight() == right);
}

TEST_CASE( "Huffman node copy constructor test", "[huffman_node(const huffman_node& old_huffman_node)]" ) {
	shared_ptr<huffman_node> left(new huffman_node('a', 1, nullptr, nullptr));
	shared_ptr<huffman_node> right(new huffman_node('b', 2, nullptr, nullptr));
	huffman_node h_1 = huffman_node('c', 3, left, right);   
	huffman_node h_2(h_1);
	REQUIRE(h_1.getLetter() == h_2.getLetter());
    REQUIRE(h_1.getFrequency() == h_2.getFrequency());	
    REQUIRE(h_1.getLeft() == h_2.getLeft());
    REQUIRE(h_1.getRight() == h_2.getRight());
}

TEST_CASE("Huffman node move constructor test", "[huffman_node(const huffman_node&& old_huffman_node)]") {
	shared_ptr<huffman_node> left(new huffman_node('a', 1, nullptr, nullptr));
	shared_ptr<huffman_node> right(new huffman_node('b', 2, nullptr, nullptr));
	huffman_node h_1 = huffman_node('c', 3, left, right);   
	huffman_node h_2 = move(h_1);
	REQUIRE(h_2.getLetter() == 'c');
    REQUIRE(h_2.getFrequency() == 3);	
    REQUIRE(h_2.getLeft() == left);
    REQUIRE(h_2.getRight() == right);

	REQUIRE(h_1.getLetter() == 0);
    REQUIRE(h_1.getFrequency() == 0);	
    REQUIRE(h_1.getLeft() == nullptr);
    REQUIRE(h_1.getRight() == nullptr);
}

TEST_CASE("Huffman node assignment operator test", "[operator=(const huffman_node& other_huffman_node)]"){
	shared_ptr<huffman_node> left(new huffman_node('a', 1, nullptr, nullptr));
	shared_ptr<huffman_node> right(new huffman_node('b', 2, nullptr, nullptr));
	huffman_node h_1 = huffman_node('c', 3, left, right);  
	huffman_node h_2 = h_1;

	REQUIRE(h_1.getLetter() == h_2.getLetter());
    REQUIRE(h_1.getFrequency() == h_2.getFrequency());	
    REQUIRE(h_1.getLeft() == h_2.getLeft());
    REQUIRE(h_1.getRight() == h_2.getRight());


}

TEST_CASE("Huffman node move assignment operator test", "[operator=(const huffman_node&& other_huffman_node)]"){
	shared_ptr<huffman_node> left(new huffman_node('a', 1, nullptr, nullptr));
	shared_ptr<huffman_node> right(new huffman_node('b', 2, nullptr, nullptr));
	huffman_node h_1 = huffman_node('c', 3, left, right);  
	huffman_node h_2 = move(h_1);

	REQUIRE(h_2.getLetter() == 'c');
    REQUIRE(h_2.getFrequency() == 3);	
    REQUIRE(h_2.getLeft() == left);
    REQUIRE(h_2.getRight() == right);

	REQUIRE(h_1.getLetter() == 0);
    REQUIRE(h_1.getFrequency() == 0);	
    REQUIRE(h_1.getLeft() == nullptr);
    REQUIRE(h_1.getRight() == nullptr);
}

TEST_CASE("Huffman node getLetter test", "[getLetter()]"){
	huffman_node h = huffman_node('a', 1, nullptr, nullptr);

	REQUIRE(h.getLetter() == 'a');
}

TEST_CASE("Huffman node getFrequency test", "[getFrequency()]"){
	huffman_node h = huffman_node('a', 1, nullptr, nullptr);

	REQUIRE(h.getFrequency() == 1);
}

TEST_CASE("Huffman node getLeft test", "[getLeft()]"){
	shared_ptr<huffman_node> left(new huffman_node('a', 1, nullptr, nullptr));
	shared_ptr<huffman_node> right(new huffman_node('b', 2, nullptr, nullptr));
	huffman_node h = huffman_node('c', 3, left, right);

	REQUIRE(h.getLeft() == left);
}

TEST_CASE("Huffman node getRight test", "[getRight()]"){
	shared_ptr<huffman_node> left(new huffman_node('a', 1, nullptr, nullptr));
	shared_ptr<huffman_node> right(new huffman_node('b', 2, nullptr, nullptr));
	huffman_node h = huffman_node('c', 3, left, right);

	REQUIRE(h.getRight() == right);
}

TEST_CASE( "Huffman node custom constructor test 2", "[huffman_node(const shared_ptr<huffman_node>, const shared_ptr<huffman_node>)]"){
	shared_ptr<huffman_node> left(new huffman_node('a', 1, nullptr, nullptr));
	shared_ptr<huffman_node> right(new huffman_node('b', 2, nullptr, nullptr));
	huffman_node h = huffman_node(left, right);
	REQUIRE(h.getLetter() == '\0');
    REQUIRE(h.getFrequency() == left->getFrequency() + right->getFrequency());	
    REQUIRE(h.getLeft() == left);
    REQUIRE(h.getRight() == right);
}