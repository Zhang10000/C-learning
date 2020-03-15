class Solution {
public:
	bool isSymmetrical(TreeNode* pRoot) {
		if (!pRoot)
			return true;
		return isS(pRoot, pRoot);
	}
	bool isS(TreeNode* pR, TreeNode* pL) {
		if (pR == NULL && pL == NULL)
			return true;
		if (pR == NULL || pL == NULL)
			return false;
		if (pR->val != pL->val)
			return false;
		return isS(pR->left, pL->right) && isS(pR->right, pL->left);
	}
};
