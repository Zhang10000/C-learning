class Solution {
public:
	vector<int> tmp;
	void to_str(TreeNode *root) {
		if (!root) tmp.push_back(0xFFFFFFFF);
		else {
			tmp.push_back(root->val);
			to_str(root->left);
			to_str(root->right);
		}
	}
	TreeNode* to_tree(int* &p) {
		if (*p == 0xFFFFFFFF) {
            p++;
			return NULL;
		}
		TreeNode* node = new TreeNode(*p);
		p++;
		node->left = to_tree(p);
		node->right = to_tree(p);
		return node;
	}
	char* Serialize(TreeNode *root) {
		tmp.clear();
		to_str(root);
		int bufSize = tmp.size();
		int *res = new int[bufSize];
		for (int i = 0; i < bufSize; i++) res[i] = tmp[i];
		return (char*)res;
	}
	TreeNode* Deserialize(char *str) {
		int *p = (int*)str;
		return to_tree(p);
	}
};
