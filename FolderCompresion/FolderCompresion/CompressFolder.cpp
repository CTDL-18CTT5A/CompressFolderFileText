#include "CompressFolder.h"

void CompressFolder::compressFolder(string folder_path)
{
	FolderReader fd;

	vector<string> allNames = fd.get_all_files_names_within_folder(folder_path);
	//fd.create_folder(folder_path + "_de");



	int k = folder_path.find_last_of("/");
	string pathEnFolder = folder_path.substr(k + 1);

	for (int i = 0; i < allNames.size(); i++) {

		/*HuffmanTree hc;

		string filename = "few-word.txt";
		int k = filename.find_last_of(".");
		string filename_de = filename.substr(0, k);

		hc.createCodeTree(filename);
		hc.encodeFile(filename);*/

		HuffmanTree hmf;

		int k = allNames.at(i).find_last_of(".");
		string filename_de = allNames.at(i).substr(0, k);

		hmf.createCodeTree(folder_path + "/" + allNames.at(i));
		hmf.encodeFile(folder_path + "/" + allNames.at(i), pathEnFolder + "_de/");
	}
}

void CompressFolder::decompressFolder(string folder_de_path)
{
	FolderReader fd;

	vector<string> allNames = fd.get_all_files_names_within_folder(folder_de_path);

	for (int i = 0; i < allNames.size(); i++) {

		HuffmanTree hmf;

		int k = folder_de_path.find_last_of("/");
		int z = folder_de_path.find_last_of("_");
		int t = allNames.at(i).find_last_of(".");

		string folderName = folder_de_path.substr(k + 1, z - k - 1);
		string filename_de = allNames.at(i).substr(0, t);


		hmf.createCodeTree(folderName + "/" + filename_de + ".txt");
		hmf.decodeFile(folder_de_path + "/" + filename_de + ".bin");
	}
	
}
