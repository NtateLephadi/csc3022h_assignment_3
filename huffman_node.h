#include <memory>

#ifndef HUFFMAN_NODE_H
#define HUFFMAN_NODE_H

class huffman_node{

	private:
		char letter;
		int frequency;
		std::shared_ptr<huffman_node> left;
		std::shared_ptr<huffman_node> right;

	public:

		huffman_node();

		huffman_node(char letter, int frequency, const std::shared_ptr<huffman_node> l, const std::shared_ptr<huffman_node> r);

		~huffman_node();

		huffman_node(const huffman_node& old_huffman_node);

		huffman_node(huffman_node&& old_huffman_node);

		huffman_node(std::shared_ptr<huffman_node> l, std::shared_ptr<huffman_node> r);

		huffman_node& operator=(const huffman_node& other_huffman_node);

		huffman_node& operator=(huffman_node&& other_huffman_node);

		char getLetter() const;

		int getFrequency() const;

		std::shared_ptr<huffman_node> getLeft()  const;

		std::shared_ptr<huffman_node> getRight() const;
};

#endif