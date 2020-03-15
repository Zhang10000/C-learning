class Solution {
public:
	vector<vector<int> > Print(TreeNode* pRoot) {
		vector<vector<int>>arr;
		vector<TreeNode*> tmp0;
		vector<int> tmp1;
		if (!pRoot)
			return arr;
		tmp0.push_back(pRoot);
		int i = 0;
		int j = tmp0.size();
		while (i != j) {
			for (; i < j; i++) {
				tmp1.push_back(tmp0[i]->val);
				if (tmp0[i]->left)
					tmp0.push_back(tmp0[i]->left);
				if (tmp0[i]->right)
					tmp0.push_back(tmp0[i]->right);
			}
			arr.push_back(tmp1);
			tmp1.clear();
			j = tmp0.size();
		}
		return arr;
	}
};
int tmp[10] = { 8,6,10,5,7,9,11,6,7,9 };
vector<int> arr(tmp, tmp + 10);
TreeNode* Createtree(size_t k) {
	TreeNode* head = NULL;
	if (k < arr.size()) {
		head = new TreeNode(arr[k]);
		head->left = Createtree(2 * k + 1);
		head->right = Createtree(2 * k + 2);
	}
	return head;
}
int main() {
	Solution s;
	vector<vector<int>> tr = s.Print(Createtree(0));
	for (size_t i = 0; i < tr.size(); i++) {
		for (auto e : tr[i])
			cout << e << ' ';
		cout << endl;
	}
	return 0;
}
