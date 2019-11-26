#pragma once

#include"HuffmanTree.h"
#include"FolderReader.h"

class CompressFolder
{
private:
	HuffmanTree hmf;
	FolderReader fd;

public:
	CompressFolder() {}
	void compressFolder(string folder_path);
	void decompressFolder(string folder_de_path);


};

