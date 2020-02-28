#include"learning.h"


struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};
class Solution1 {
public:
	bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2) {
		if (!pRoot1 || !pRoot2)
			return false;
		return (tree(pRoot1, pRoot2)) || HasSubtree(pRoot1->left, pRoot2) || HasSubtree(pRoot1->right, pRoot2);
	}
	bool tree(TreeNode* pRoot1, TreeNode* pRoot2) {
		if (!pRoot2)
			return true;
		if (!pRoot1)
			return false;
		if (pRoot1->val != pRoot2->val)
			return false;
		return tree(pRoot1->left, pRoot2->left) && tree(pRoot1->right, pRoot2->right);
	}
};
class Solution2 {
public:
	void Mirror(TreeNode *pRoot) {
		if (!pRoot)
			return;
		Mirror(pRoot->left);
		Mirror(pRoot->right);
		TreeNode * tmp = pRoot->left;
		pRoot->left = pRoot->right;
		pRoot->right = tmp;
	}
};
