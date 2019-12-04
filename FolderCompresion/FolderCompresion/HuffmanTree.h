#pragma once

#ifndef __huffman__HuffmanTree__
#define __huffman__HuffmanTree__

#include <iostream>
#include <string>
#include <queue>
#include <fstream>
#include <bitset>
#include "BST.h"

using namespace std;

class CharFreq
{
public:
	// Mỗi kí tự đọc từ file sẽ đc lưu như sau:
	unsigned char letter;  // Kí tự đó là kí tự gì
	float frequency; // Số lần xuất hiện là bao nhiêu
	string encoding; // Mã code Huffman khi mã hóa là gì. Tạm thời khi khopiwr tạo để trống

	// Phương thức tạo lập đối tượng
	CharFreq() :letter('\0'), frequency(0), encoding("") { }
	CharFreq(unsigned char l, float f) :letter(l), frequency(f), encoding("") { }
	
	bool operator>(const CharFreq &rhs) const
	{
		return frequency > rhs.frequency;
	}
};


class HuffmanTree : BST<CharFreq>
{

private:

	// Cây Huff sẽ có thông tin bao gồm. Một mảng các Node và Node gốc của cây
	// Mỗi Node bao gồn thông tin: char data, freq, string code;
	std::vector<BST<CharFreq>::BSTNode*> freqArr;
	BST<CharFreq>::BSTNode* root;

	// Phương thứuc nội bộ để duyệt ngược cây từ lá về gốc để sinh code
	int traverseAndPrint(ofstream& decodedfile, string& bits, int i, BSTNode* cur);


public:
	// Constructor
	HuffmanTree() {}
	
	// Tạo cây Huffman
	bool createCodeTree(string filename);
	
	// Mã hóa dựa vào cây Huff
	bool encodeFile(string originalFilename, string outputFilename = "");
	
	// Giải mã dựa vào cây Huff
	bool decodeFile(string filename);
};

ostream& operator<<(ostream &out, HuffmanTree &code);

#endif
