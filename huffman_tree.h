#include "huffman_node.h"
#include <unordered_map>
#include <memory>
#include <iostream>
#include <fstream>
#include <string>
#include <queue>

#ifndef HUFFMAN_TREE_H
#define HUFFMAN_TREE_H

struct compare_huffman_node{
    bool operator()(const huffman_node& lhs, const huffman_node& rhs)
    {
        return lhs.getFrequency() > rhs.getFrequency();
    }
};

class huffman_tree{

public:
	std::shared_ptr<huffman_node> root;
	std::unordered_map<char, int> huffman_node_map;
	std::priority_queue<huffman_node, std::vector<huffman_node>, compare_huffman_node> huffman_node_queue;
	std::unordered_map<char, std::string> code_table;

public:

	huffman_tree();

	~huffman_tree();

	void make_huffman_node_map(std::string inputFile) throw();

	void make_huffman_node_queue();

	void visit(std::shared_ptr<huffman_node> node, std::string binary_code);

	void in_order(std::shared_ptr<huffman_node> node, std::string binary_code);

	void compress(std::string inputFile, std::string outputFile);

};


#endif