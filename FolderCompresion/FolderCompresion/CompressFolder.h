#define _CRT_SECURE_NO_WARNINGS 1

#pragma once

#include"HuffmanTree.h"
#include"FolderReader.h"

class CompressFolder
{
public:
	CompressFolder() {}
	void compressFolder(string folder_path);
	void decompressFolder(string folder_de_path);


};

