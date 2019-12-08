#include"CompressFolder.h"

#include <iostream>
#include<string>
using namespace std;

void main_menu()
{
	int choose = 0;
	string paths = "";

	while (1) {
		system("cls");

		cout << "\n------------ M E N U ------------------\n\n";
		cout << "1. File compress.\n";
		cout << "2. File decompress.\n";
		cout << "3. Folder compress.\n";
		cout << "4. Folder decompress.\n\n";
		cout << ">> You choose ? ";

		cin >> choose;
		cin.ignore();

		switch (choose)
		{
		case 0: {
			return;
		}
		case 1: {
			cout << "\n>> Enter File path: ";
			getline(cin, paths);
			cin.ignore(0);

			cout << endl;

			HuffmanTree hmf;

			hmf.createCodeTree(paths);
			hmf.encodeFile(paths);

			break;
		}
		case 2: {
			cout << "\n>> Enter File path: ";
			getline(cin, paths);
			cin.ignore(0);
			cout << endl;


			HuffmanTree hmf;

			hmf.createCodeTree(paths);
			hmf.decodeFile(paths);

			break;
		}

		case 3: {
			cout << "\n>> Enter folder compress path: ";
			getline(cin, paths);
			cin.ignore(0);

			CompressFolder cf;

			cf.compressFolder(paths);

			break;
		}

		case 4: {
			cout << "\n>> Enter folder decompress path: ";
			getline(cin, paths);
			cin.ignore(0);

			CompressFolder cf;

			cf.decompressFolder(paths);

			break;
		}

		default:
			break;
		}

		cout << endl;
		system("pause");
	}
}


int main()
{
	main_menu();

    return EXIT_SUCCESS;
}

























