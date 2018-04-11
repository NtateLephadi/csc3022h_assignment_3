#include "huffman_tree.h"
#include "huffman_node.h"

using namespace std;

huffman_tree::huffman_tree(){
	huffman_tree::huffman_node_map = unordered_map<char, int> ();
	huffman_tree::code_table = unordered_map<char, string> ();
	huffman_tree::huffman_node_queue = priority_queue<huffman_node, vector<huffman_node>, compare_huffman_node> ();
}

huffman_tree::~huffman_tree(){
	huffman_tree::root = nullptr;
}

void huffman_tree::make_huffman_node_map(string inputFile) throw(){
	
	ifstream ifs(inputFile);

	while(ifs.good()){

		char letter = ifs.get();
		
		if(huffman_node_map.find(letter)==huffman_node_map.end()){
			huffman_node_map.insert({letter,1});
		}
		else{
			huffman_tree::huffman_node_map.at(letter) += 1;
		}
	}

	ifs.close();
}

void huffman_tree::make_huffman_node_queue(){

	for(auto& u_map: huffman_tree::huffman_node_map){
		huffman_tree::huffman_node_queue.push(huffman_node(u_map.first, u_map.second, nullptr, nullptr));
	}

	while((int)huffman_node_queue.size() > 1){
		shared_ptr<huffman_node> l(new huffman_node(huffman_node_queue.top().getLetter(), huffman_node_queue.top().getFrequency(), huffman_node_queue.top().getLeft(), huffman_node_queue.top().getRight()));
		huffman_node_queue.pop();
		shared_ptr<huffman_node> r(new huffman_node(huffman_node_queue.top().getLetter(), huffman_node_queue.top().getFrequency(), huffman_node_queue.top().getLeft(), huffman_node_queue.top().getRight()));
		huffman_node_queue.pop();
		huffman_node p = huffman_node(l, r);
		huffman_node_queue.push(p);
	}

	huffman_node root = huffman_node(huffman_node_queue.top());
	shared_ptr<huffman_node> root_ptr(new huffman_node(root));
	in_order(root_ptr, "");
}

void huffman_tree::visit(shared_ptr<huffman_node> node, std::string binary_code){
	if( node->getLetter() != '\0'){
		code_table.insert({node->getLetter(), binary_code});
	}
}

void huffman_tree::in_order(shared_ptr<huffman_node> node, std::string binary_code){

 	if (node != nullptr){
        in_order (node->getLeft(), binary_code + "0");
        visit (node, binary_code);
        in_order (node->getRight(), binary_code + "1");
  	}	
}

void huffman_tree::compress(string inputFile, string outputFile){
	string buffer = "";
	ifstream ifs(inputFile);
	while(ifs.good()){
		char letter = ifs.get();
		buffer += code_table.at(letter);
	}
	ifs.close();

	ofstream ofs(outputFile);
	const char* buffer_ptr = buffer.c_str();
	ofs.write(buffer_ptr,buffer.length());
	ofs.close();

	

	ofstream ofs1(outputFile + ".hdr");
	ofs1 << code_table.size() << endl;
	for (auto& u_map: code_table){
		ofs1 << u_map.first << ": " << u_map.second << endl;
	}
	ofs1.close();
}