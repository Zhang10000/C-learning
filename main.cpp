#include<iostream>
#include<vector>
#include<gdiplusbitmap.h>
using namespace std;

class TreeNode {
public:
	int val;
	TreeNode * Left;
	TreeNode * Right;
};

class Solution {
public:
	TreeNode* Convert(TreeNode* pRootTree) {
		TreeNode* root = pRootTree;
		if (root == nullptr)return nullptr;
		// ×ó
		TreeNode * left = Convert(root->Left);
		TreeNode * right = Convert(root->Right);

		if (root->Left) {
			TreeNode * p = left;
			while (p->Right != nullptr)p = p->Right;
			p->Right = root;
			root->Left = p;
		}
		if (root->Right) {
			root->Right = right;
			right->Left = root;
		}
		if (root->Left != nullptr)return left;
		return root;
	}
};

