#define _CRT_SECURE_NO_WARNINGS 1

#pragma once

#include"HuffmanTree.h"
#include"FolderReader.h"

class CompressFolder
{
public:
	// Phương thức khởi tạo Compress đối tượng
	CompressFolder() {}

	// Nén Folder:
	void compressFolder(string folder_path);

	// Giải nén Folder
	void decompressFolder(string folder_de_path);
};

