#include <iostream>
#include "HuffmanTree.h"

using namespace std;


int main(int argc, const char * argv[])
{
	HuffmanTree hc;

	
	//Testing with a short pararaph
	hc.createCodeTree("test.txt");
	hc.encodeFile("test.txt", "encoded.bin");
	hc.decodeFile("encoded.bin");
	
    return 0;
}

























