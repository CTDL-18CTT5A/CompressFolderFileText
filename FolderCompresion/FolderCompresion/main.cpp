#include <iostream>
#include"CompressFolder.h"

using namespace std;

int main()
{
	/*HuffmanTree hc;

	string filename = "few-word.txt";
	int k = filename.find_last_of(".");
	string filename_de = filename.substr(0, k);

	hc.createCodeTree(filename);
	hc.encodeFile(filename);
	hc.decodeFile(filename_de + ".bin");*/



	/*FolderReader fd;
	string paths = "F:/CloneHuffman/Build/Clone/Com/CompressFolderFileText/FolderCompresion/FolderCompresion/data_format_txt";

	vector <string> names = fd.get_all_files_names_within_folder(paths);

	for (int i = 0; i < names.size(); i++) {
		cout << names.at(i) << endl;
	}*/


	/*string paths = "F:/CloneHuffman/Build/Clone/Com/CompressFolderFileText/FolderCompresion/FolderCompresion/data_format_txt";
	int k = paths.find_last_of("/");
	string folderCom = paths.substr(k + 1);

	FolderReader fd;

	fd.create_folder(folderCom + "_de");*/


	CompressFolder cf;

	string paths = "F:/CloneHuffman/Build/Clone/Com/CompressFolderFileText/FolderCompresion/FolderCompresion/data_format_txt";
	cf.compressFolder(paths);


	/*ifstream in_file("data_format_txt/sieu nhan do.txt", ios::in);

	string s;

	if (in_file.is_open()) {
		while (!in_file.eof())
		{
			in_file >> s;
			cout << s;
		}
	}
	else {
		cout << "ERROR: Loading fail!" << endl;
	}*/
	
    return EXIT_SUCCESS;
}

























