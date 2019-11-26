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

	FolderReader(){}
	vector<string> get_all_files_names_within_folder(string folder);
	void create_folder(string folderName);
};

