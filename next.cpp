class Solution {
public:
	TreeLinkNode* GetNext(TreeLinkNode* pNode){
		if (!pNode)
			return nullptr;
		TreeLinkNode* node = nullptr;
		if (pNode->right) {
			TreeLinkNode* tmp = pNode->right;
			while (tmp->left)
				tmp = tmp->left;
			node = tmp;
		}
		else if (pNode->next != nullptr) {
			TreeLinkNode* tmp = pNode;
			TreeLinkNode* ftmp = pNode->next;
			while (ftmp != nullptr && ftmp->right == tmp) {
				tmp = ftmp;
				ftmp = ftmp->next;
			}
			node = ftmp;
		}
		return node;
	}
};
