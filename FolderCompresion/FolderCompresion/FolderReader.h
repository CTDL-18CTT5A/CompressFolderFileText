#pragma once

#define _CRT_SECURE_NO_WARNINGS 1

#include <process.h> 
#include <windows.h>
#include <tchar.h>
#include <vector>
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

class FolderReader
{
public:
	// Sử dụng thư viện windows để hỗ trợ việc lấy tên file trong một thư mục

	// Phương thức tạo lập
	FolderReader(){}

	// Phương thức lấy tên tất cả các File trong thư mục:
	vector<string> get_all_files_names_within_folder(string folder);

	// Phương thức tạo mới 1 Folder
	void create_folder(string folderName);
};

