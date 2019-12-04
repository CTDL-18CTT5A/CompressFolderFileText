#include "HuffmanTree.h"

#include<iostream>
using namespace std;

// Phương thức tạo cây Huffman
bool HuffmanTree::createCodeTree(string filename)
{
	priority_queue<	BST<CharFreq>::BSTNode*, vector<BST<CharFreq>::BSTNode*>, BST<CharFreq>::FrequencyCompare> myPriorityQ;

	string str, allText = "", charCode = "", temp = "";
	// Các Object dummy phục vụ quá trình đọc dữ liệu từ file, và lưu trử trung gian trong cây Huffman

	ifstream infile;
	queue<BST<CharFreq>::BSTNode*> encodeQ;
	vector<BST<CharFreq>::BSTNode*> arr;
	BST<CharFreq>::BSTNode* ptr;
	int count = 0;
	// Đọc file input đầu vào
	infile.open(filename.c_str());
	 
	if( !infile.is_open() ){
		cout << "ERROR: Loading file!\n";
		return false;
	}

	// Lưu hết data đọc từ file vào một biến duy nhất là allText (mỗi dòng đọc từ file cách nhau bởi kí tự \n)
	while(!infile.eof()){
		getline(infile,str);
		allText += str + "\n";
	}
	infile.close();

	// Duyệt từng kí tự 1 của chuổi allText
	for(unsigned int i = 0; i < allText.length(); i++){

		// Nếu ở lần lặp đầu tiên (i=0) thì ta tạo ra một Node mới mang dữ liệu là allText[i] và tần số là 1. Sau đó đẩy nó vào mảng arr
		if(count == 0){
			BST<CharFreq>::BSTNode* temptr = new BST<CharFreq>::BSTNode();
			temptr->data.letter = allText[i];
			temptr->data.frequency = 1;
			arr.push_back(temptr);
			count++;
	  
		}else{

			// Duyệt từ đầu tới vị trí i hiện tại của chuổi allText
			int index = 0;

			// Ví dụ chuổi "aabbcc" thì khi i = 1 thì ta thấy điều kiện duyệt từ 0 đến 1 của index không thể thõa vòng while nên index không tăng.
			// Ta xuống check đk if
			while(index < count && allText[i] != arr[index]->data.letter){
				index++;
			}
	  
			// Nếu phần tử allText[i] đã xuất hiện trong mảng arr rồi thì tăng freq lên 1
			if(index < count){
				arr[index]->data.frequency++;
	  
			// Ngược lại: Nếu index >= count thì có nghĩa là kí tự này chưa được xuất hiện nên ta thêm vào mảng arr
			}else{
				BST<CharFreq>::BSTNode* temptr = new BST<CharFreq>::BSTNode();
				temptr->data.letter = allText[i];
				temptr->data.frequency = 1;
				arr.push_back(temptr);
				count++;
			}
		}
	}

	  // Tiếp theo, ta xây cây bằng hàng đợi ưu tiên với độ ưu tiên thấp (Thấp nhất được ra trước nhất)
	for(int i = 0; i < count; i++){
		myPriorityQ.push(arr[i]);
	}

	// Ta gắn Node root và ghép 2 Node có freq nhỏ nhất lại và nhét nó vào hàng đợi ưu tiên thấp
	root = nullptr;
	while(!myPriorityQ.empty()){
		
		// Khi ta gộp tần số xuất hiện của 2 cặp thì đến khi chỉ còn 1 Node trong hàng đợi thì ta gắn cho nó là Node root
		// Như vậy ta có được 1 cây huffman với node root nhờ hàng đợi ưu tiên bé.
		if(myPriorityQ.size() == 1){
		    root = myPriorityQ.top();
		    myPriorityQ.pop();
		
		}else{
		    // Ngược lại, ta khởi tạo 1 Node giả. Sau đó lấy 2 thằng có freq bé nhất làm 2 con của Node giả đó, cập nhập
		    // Freq của Node giả bằng tổng Freq của 2 thằng con. Ta push node giả đó lại vào hàng đợi. Cứ tiếp tục như thế 
		    // đến khi hàng đợi rỗng
		    BST<CharFreq>::BSTNode* temptr = new BST<CharFreq>::BSTNode();

		    temptr->left = myPriorityQ.top();
		    myPriorityQ.pop();
		    temptr->right = myPriorityQ.top();
		    myPriorityQ.pop();
	  
		    temptr->data.frequency = temptr->left->data.frequency + temptr->right->data.frequency;
			temptr->data.encoding = "";
		    myPriorityQ.push(temptr);
		}
	}

	// Ta duyệt cây để tạo mã Code cho mỗi kí tự
	arr.resize(256);

	encodeQ.push(root);

	while(!encodeQ.empty()){
		ptr = encodeQ.front();
		encodeQ.pop();

		// Duyệt tới khi nào đến nút là thì cập nhập lại mảng arr (chỉ là mảng trung gian) tại vị trí (int)ptr->data.letter là đoạn code đường đi vừa tạo ra
		if(ptr->left != nullptr){

		// Nếu đi về bên trái thì: Mã Code hiện tại += "0"
		// Nếu đi về bên phải thì: Mã Code hiện tại += "1"
		ptr->left->data.encoding = ptr->data.encoding + "0";
		ptr->right->data.encoding = ptr->data.encoding + "1";

		    encodeQ.push(ptr->left);
		    encodeQ.push(ptr->right);
		}else
		    // Gặp Node lá:
		    arr[(int)ptr->data.letter] = ptr;
	}

	// Gán giá trị cho mảng tần số chính bằng mảng trung gian
	freqArr = arr;
  
	return true;
}

// Encoding nhận tham số đầu vào là tên File input và tên File output. Kết quả trả về là một file nhị phân được mã hóa từ file đầu vào
bool HuffmanTree::encodeFile(string originalFilename, string outputFilename)
{
	string str;
	string allText = "";

	int k = originalFilename.find_last_of(".");
	string subName1 = originalFilename.substr(0, k);

	k = originalFilename.find_last_of("/");
	int z = originalFilename.find_last_of(".");
	string subName2 = originalFilename.substr(k + 1, z - k - 1);

	ifstream infile;
	infile.open(originalFilename.c_str());

	// Nếu không mở được file thì báo lỗi
	if( !infile.is_open() )
	{
		cout << "ERROR: Loading fail!\n";
		return false;
	}

	// Đọc cả file và lưu vào một chuổi allText (lưu theo dòng của File đầu vào, mỗi dòng cách nhau dấu \n)
	while(!infile.eof()) // To get you all the lines.
	{
		getline(infile,str); // Saves the line in STRING.
		allText += str + "\n";
	}
	infile.close();
	
	// Mở file output dưới dạng nhị phân
	ofstream outStream;

	if (outputFilename == "") {
		outStream.open(subName1 + ".bin", ios::binary);
	}
	else {
		outStream.open(outputFilename + subName2 + ".bin", ios::binary);
	}
	
	
	// Kiểm tra xem có mở hoàn tất hay không
	if( !outStream.is_open() )
	{
		cout << "ERROR: creating output fail!\n";
		return false;
	}
	
	// Chuổi chứa code sau khi thay thế các phần tử của chuổi allText bằng các mã Code build được từ cây huffman
	string currentStream = "";

	// Kích thước mỗi lần ghi file xuống là 8 bit
	const int WRITE_SIZE = 8;


	// Duyệt từng kí tự của file đầu vào (trong chuổi string allText)
	for (int i = 0; i < (int)allText.length(); i++) {
	    // Nếu nó là một kí tự ASC thuần [0-255] thì ta sẻ thêm đoạn code mã hóa của kí tự đó vào chuổi currentStream
	    if((int)allText[i] >= 0 && (int)allText[i] <= 255)
		    currentStream += freqArr[(int)allText[i]]->data.encoding;

	    if (i == 0) {
		    cout << "SIZE = " << allText.size() << endl;
	    }

	    // Kiểm tra xem sau khi thêm mã Code của kí tự vừa mã hóa thì chuổi currentStream có dài hơn 8 kí tự chưa
	    // Nếu chưua thì tiếp tục.
	    // Nếu rồi thì ta sẽ ngắt mỗi 8 kí tự của chuổi và ghi xuống file output

		while ((int)currentStream.length() > WRITE_SIZE)
		{
			string byte = currentStream.substr(0, WRITE_SIZE);
			bitset<8> set(byte);
			const char toWrite = (unsigned char)((unsigned int)set.to_ulong());
			outStream.write(&toWrite, sizeof(char));
			currentStream = currentStream.substr(WRITE_SIZE, currentStream.length() - WRITE_SIZE);
		}
	}
	
	outStream.close();
	return false;
}

// Decoding nhận tham số đầu vào là tên File input đã được mã hóa và tên File output sau khi giãi nén thành công
bool HuffmanTree::decodeFile(string filename)
{
	// Đọc file dưới dạng nhị phân (File vào)
	ifstream encodedfile;
	encodedfile.open(filename.c_str(), ios::binary);

	int k = filename.find_last_of("/");
	int z = filename.find_last_of(".");
	string subName = filename.substr(0, k - 3);
	string subName2 = filename.substr(k + 1, z - k - 1);

	// Đọc file dưới dạng nhị phân (File ra)
	ofstream decodedfile;
	decodedfile.open((subName + "_de/" + subName2 + "_de.txt").c_str(), ios::out);

	// Kiểm tra xem có mở được hay không
	if( !encodedfile.is_open() )
	{
		cout << "ERROR: opening encoded fail!\n";
		return false;
	}
	
	// Đọc từng kí tự đầu vào mà không bỏ qua khoảng trắng
	encodedfile >> noskipws;
	
	// Chuổi chứa toàn bộ mã code lúc đầu lưu xuống file
	string bitStream = "";

	while(!encodedfile.eof())
	{
		// Đọc từng byte và chuyển 8 bit đó thành mã string đồng thời cộng dồn vào chuổi bitStream
		unsigned char readMe;
		encodedfile >> readMe;
		bitset<8> set((unsigned long)readMe);
		bitStream += set.to_string();
	}

	encodedfile.close();

	// Duyệt qua từng kí tự của chuổi bitStream
	int i=0;

	while(i != -1)
	{
	  i = traverseAndPrint(decodedfile, bitStream, i, root);
	}

	decodedfile.close();

	return false;
}


int HuffmanTree::traverseAndPrint(ofstream& decodedfile, string &bits, int i, BSTNode *cur)
{
    if(i >= (int)bits.length())
		return -1;

  /*
  * Duyệt qua từng kí tự của chuổi bits. Nếu
  * + bits[i] là kí tự 0 và bits[i] là Node lá thì ta trả về kí tự tại node đó (Lấy 8 bits tiếp theo và trả về kí tự có code là 8 bit đó)
  * + bist[i] là kí tự 0 thì ta sẽ đi về bên trái của Node hiện tại (cur)
  * + bist[i] là kí tự 1 thì ta sẽ đi về bên phải của Node hiện tại (cur)
  */


    if(cur->left == nullptr){
	    decodedfile << cur->data.letter;
	    cout<< cur->data.letter;
		return i;
    }else{
	    if(bits[i] == '0')
			return traverseAndPrint(decodedfile, bits, i+1, cur->left);
		else
			return traverseAndPrint(decodedfile, bits, i+1, cur->right);
    }
}