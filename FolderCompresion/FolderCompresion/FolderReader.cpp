#include "FolderReader.h"
#include<direct.h>
#include<string>

// Lấy toàn bộ tên các file có trong thư mục Folder truyền vào. Phương thức trả về một vector chứa tên.
vector<string> FolderReader::get_all_files_names_within_folder(string folder)
{
	vector<string> names;

	string search_path = folder + "/*.*";
	WIN32_FIND_DATA fd;
	HANDLE hFind = ::FindFirstFile(search_path.c_str(), &fd);

	if (hFind != INVALID_HANDLE_VALUE) {

		do {
			if (!(fd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)) {
				names.push_back(fd.cFileName);
			}

		} while (::FindNextFile(hFind, &fd));

		::FindClose(hFind);
	}
	return names;
}

// Tạo ra một Folder
void FolderReader::create_folder(string folderName)
{
	char* dirname = new char(folderName.length()+1);

	strcpy(dirname, folderName.c_str());

	int k = _mkdir(dirname);
}
