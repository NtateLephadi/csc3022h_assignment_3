CFLAGS = -O
CC = g++

huffencode: huffman_tree.o huffman_node.o huffencode.o
	g++ huffencode.cpp huffman_tree.cpp huffman_node.cpp -o huffencode --std=c++11

huffman_node.o: huffman_node.cpp
	g++ -c huffman_node.cpp --std=c++11

huffman_tree.o: huffman_node.o
	g++ -c huffman_tree.cpp --std=c++11

huffencode.o: huffman_tree.o huffman_node.o
	g++ -c huffencode.cpp --std=c++11

huffman_node_test.o: huffman_node_test.cpp
	g++ -c huffman_node_test.cpp --std=c++11

huffencode_test: huffman_node_test.o huffman_node_test.o
	g++ huffman_node.cpp huffman_node_test.cpp -o huffencode_test --std=c++11

run:
	./huffencode

test:
	./huffencode_test

clean:
	rm -f core *.o huffencode
