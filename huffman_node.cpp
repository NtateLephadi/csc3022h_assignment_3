#include "huffman_node.h"

using namespace std;

huffman_node::huffman_node() : letter(0), frequency(0){
}

huffman_node::huffman_node(char letter, int frequency, const shared_ptr<huffman_node> l, const shared_ptr<huffman_node> r) : letter(letter), frequency(frequency), left(l), right(r){
}

huffman_node::~huffman_node(){}

huffman_node::huffman_node(const huffman_node& old_huffman_node) : letter(old_huffman_node.letter), frequency(old_huffman_node.frequency), left(old_huffman_node.left), right(old_huffman_node.right){
}

huffman_node::huffman_node(huffman_node&& old_huffman_node) : letter(old_huffman_node.letter), frequency(old_huffman_node.frequency), left(old_huffman_node.left), right(old_huffman_node.right){
	old_huffman_node.letter = old_huffman_node.frequency = 0;	
	old_huffman_node.left = old_huffman_node.right = nullptr;
}

huffman_node& huffman_node::operator=(const huffman_node& other_huffman_node){
	if(this == &other_huffman_node){
		return *this;
	}

	letter = other_huffman_node.letter;
	frequency = other_huffman_node.frequency;
	left = other_huffman_node.left;
	right = other_huffman_node.right;

	return *this;
}

huffman_node& huffman_node::operator=(huffman_node&& other_huffman_node){
	if(this == &other_huffman_node){
		return *this;
	}

	letter = other_huffman_node.letter;
	frequency = other_huffman_node.frequency;
	left = other_huffman_node.left;
	right = other_huffman_node.right;

	other_huffman_node.letter = 0;
	other_huffman_node.frequency = 0;
	other_huffman_node.left = nullptr;
	other_huffman_node.right = nullptr;

	return *this;
}

char huffman_node::getLetter() const{
	return letter; 
}

int huffman_node::getFrequency() const{
	return frequency;
}

shared_ptr<huffman_node> huffman_node::getLeft() const{
	return left;
}

shared_ptr<huffman_node> huffman_node::getRight() const{
	return right;
}

huffman_node::huffman_node(shared_ptr<huffman_node> l, shared_ptr<huffman_node> r){
	left = l;
	right = r;
	letter = '\0';
	frequency = l->getFrequency() + r->getFrequency();
}