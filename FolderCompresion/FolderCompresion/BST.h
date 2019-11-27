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
	  BSTNode():left(NULL), right(NULL){}//ask
	  BSTNode(TYPE cf):left(NULL), right(NULL),data(cf){ }
	  BSTNode(BSTNode *l, BSTNode *r, TYPE cf):left(l), right(r),data(cf){ }
	  BSTNode(BSTNode *l, BSTNode *r):left(l), right(r){}//ask
	  BSTNode *left, *right;
	  TYPE data;
	};
	
	class FrequencyCompare
	{
	public:
		FrequencyCompare() { }
		
		bool operator() (const BSTNode *lhs, const BSTNode *rhs) const
		{
			// Changing the comparison will change the priority queue ordering (min vs max)
			return lhs->data > rhs->data;
		}
	};
	
	BSTNode *root;
	
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
	BST() :root(NULL) {}
	virtual ~BST() { eraseTree(root); }
};

#endif
