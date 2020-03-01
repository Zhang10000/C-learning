class Solution5 {
public:
	vector<int> PrintFromTopToBottom(TreeNode* root) {
		queue<TreeNode*> que;
		vector<int> arr;
		if (root == NULL)
			return arr;
		que.push(root);
		while (!que.empty()) {
			arr.push_back(que.front()->val);
			if (que.front()->left)
				que.push(que.front()->left);
			if (que.front()->left)
				que.push(que.front()->left);
			que.pop();
		}
		return arr;
	}
};
