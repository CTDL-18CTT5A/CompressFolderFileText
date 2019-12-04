#pragma once

#ifndef huffman_BST_h
#define huffman_BST_h

template<typename TYPE>
class BST
{
protected:public:
	class BSTNode
	{
	public:
		// Một node của cây Huffman sẽ có các thông tin sau:
	  BSTNode *left, *right; // Con trỏ tới node con trái và phải
	  TYPE data; // Giá trị lưu trữ tại node đó

	  // Phưong thức khởi tạo
	  BSTNode() :left(NULL), right(NULL) {}//ask
	  BSTNode(TYPE cf) :left(NULL), right(NULL), data(cf) { }
	  BSTNode(BSTNode* l, BSTNode* r, TYPE cf) :left(l), right(r), data(cf) { }
	  BSTNode(BSTNode* l, BSTNode* r) :left(l), right(r) {}//ask
	};
	
	class FrequencyCompare
	{
	public:
		FrequencyCompare() { }
		
		// Đối số compare để thay đổi hàng đợi ưu tiên (Hàng đợi có độ ưu tiên cao sang hàng đợi có độ ưu tiên thấp hoặc ngược lại)
		bool operator() (const BSTNode *lhs, const BSTNode *rhs) const
		{
			return lhs->data > rhs->data;
		}
	};
	
	// Một cây Huffman sẽ nắ giữa Node gốc của cây mà thôi.
	BSTNode *root;
	
	// Hủy cây Huff
	void eraseTree(BSTNode* cur)
	{
		if(cur != NULL)
		{
			eraseTree(cur->left);
			eraseTree(cur->right);
			delete cur;
		}
	}
	
public:

	// Phương thứuc khởi tạo cây Huffman
	BST() :root(NULL) {}

	// Phương thức hủy cây Huffman
	virtual ~BST() { eraseTree(root); }
};

#endif
