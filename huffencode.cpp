#include "huffman_node.h"
#include "huffman_tree.h"

using namespace std;

int main(int argc, char* argv[]) throw(){
	
	huffman_tree h;
	
	h.make_huffman_node_map((string)argv[1]);
	h.make_huffman_node_queue();
	h.compress((string)argv[1], (string)argv[2]);

	return 0;
}