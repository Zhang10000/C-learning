class Solution {
public:
	TreeNode* head = NULL;
	TreeNode* rehead = NULL;
	TreeNode* Convert(TreeNode* pRootOfTree){
		Con(pRootOfTree);
		return rehead;
	}
	void Con(TreeNode* pRootOfTree) {
		if (pRootOfTree == NULL)return;
		Con(pRootOfTree->left);
		if (head == NULL) {
			head = pRootOfTree;
			rehead = pRootOfTree;
		} else {
			head->right = pRootOfTree;
			pRootOfTree->left = head;
			head = pRootOfTree;
		}
		Con(pRootOfTree->right);
	}
};
