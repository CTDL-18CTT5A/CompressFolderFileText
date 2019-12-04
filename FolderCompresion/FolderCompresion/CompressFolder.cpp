#include "CompressFolder.h"

// Với cấu trúc thư mục như thế nào thì khi ta nén ta sẽ tạo ra một cấu trúc giống như vậy để lưu các tập file nén
void CompressFolder::compressFolder(string folder_path)
{
	FolderReader fd;

	// Lấy hêt các tên của các tập tin trong Folder đầu vào
	vector<string> allNames = fd.get_all_files_names_within_folder(folder_path);

	// Tạo Folder với cấu trúc cây như Folder đầu vào
	//fd.create_folder(folder_path + "_de");

	// Với tường tập tin trong Folder thì ta cứ việc gọi phương thức xây cây Huff sau đó mã hóa và ghi xuông file (thêm hậu tố _en vào tên tập tin)
	for (int i = 0; i < allNames.size(); i++) {

		HuffmanTree hmf;

		int k = allNames.at(i).find_last_of(".");
		string filename_de = allNames.at(i).substr(0, k);

		hmf.createCodeTree(folder_path + "/" + allNames.at(i));
		hmf.encodeFile(folder_path + "/" + allNames.at(i), folder_path + "_en/");
	}
}

void CompressFolder::decompressFolder(string folder_de_path)
{
	FolderReader fd;

	// Lấy hêt các tên của các tập tin trong Folder đầu vào
	vector<string> allNames = fd.get_all_files_names_within_folder(folder_de_path);

	// Với tường tập tin nén thì ta sẽ gọi phưogn thức tạp cây Huffman và giải nén ngược quá trình nén
	for (int i = 0; i < allNames.size(); i++) {

		HuffmanTree hmf;

		// Tách lấy tên file mã hóa
		int k = folder_de_path.find_last_of("/");
		int z = folder_de_path.find_last_of("_");
		int t = allNames.at(i).find_last_of(".");

		string folderName = folder_de_path.substr(k + 1, z - k - 1);
		string filename_de = allNames.at(i).substr(0, t);

		// Tạo cây Huffman
		hmf.createCodeTree(folderName + "/" + filename_de + ".txt");

		// Đọc file đã mã hóa và và tiến hành decode
		hmf.decodeFile(folder_de_path + "/" + filename_de + ".bin");
	}
	
}
