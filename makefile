CFLAGS = -O
CC = g++
TEST = test

huffencode: huffman_tree.o huffman_node.o huffencode.o
	g++ huffencode.cpp huffman_tree.cpp huffman_node.cpp -o huffencode --std=c++11

huffman_node.o:
	g++ -c huffman_node.cpp --std=c++11

huffman_tree.o: huffman_node.o
	g++ -c huffman_tree.cpp --std=c++11

huffencode.o: huffman_tree.o huffman_node.o
	g++ -c huffencode.cpp --std=c++11

huffman_node_test.o:
	g++ huffman_node.cpp huffman_node_test.cpp -o $(TEST)/huffman_node_test --std=c++11

test: huffman_node_test.o
	$(TEST)/./huffman_node_test

clean:
	@rm -f *.o
	@rm -f huffencode
	@rm -f test/huffman_node_test
	@rm -f *.bin
	@rm -f *.hdr
