#include "CompressFolder.h"

void CompressFolder::compressFolder(string folder_path)
{
	vector<string> allNames = fd.get_all_files_names_within_folder(folder_path);
	fd.create_folder(folder_path + "_de");

	for (int i = 0; i < allNames.size(); i++) {

		int k = allNames.at(i).find_last_of(".");
		string filename_de = allNames.at(i).substr(0, k);

		hmf.createCodeTree(folder_path + "/" + allNames.at(i));
		hmf.encodeFile(folder_path + "/" + allNames.at(i), folder_path + "_de/");
	}
}

void CompressFolder::decompressFolder(string folder_de_path)
{

	vector<string> allNames = fd.get_all_files_names_within_folder(folder_de_path);

	for (int i = 0; i < allNames.size(); i++) {

		int k = allNames.at(i).find_last_of(".");
		string filename_de = allNames.at(i).substr(0, k);

		hmf.createCodeTree(allNames.at(i));
		hmf.encodeFile(allNames.at(i));
	}
	
}
