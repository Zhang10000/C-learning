#include<vector>
#include<iostream>
using namespace std;

struct TreeNode {
     int val;
   TreeNode *left;
    TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	TreeNode* reConstructBinaryTree(vector<int> pre, vector<int> vin) {
		if (vin.size() == 0) return NULL;
		TreeNode *head = new TreeNode(pre[0]);
		for(int i = 0;i<vin.size();++i)
			if (vin[i] == pre[0]) {
				vector<int>left_pre(pre.begin() + 1, pre.begin() + i + 1);
				vector<int>right_pre(pre.begin() + i + 1, pre.end());
				vector<int>left_vin(vin.begin(), vin.begin() + i);
				vector<int>right_vin(vin.begin() + i + 1, vin.end());
				head->left = reConstructBinaryTree(left_pre, left_vin);
				head->right = reConstructBinaryTree(right_pre, right_vin);
				return head;
			}
	}
};
int main() {
	vector<int>l = { 1,2,4,7,3,5,6,8 };
	vector<int>r = { 4,7,2,1,5,3,8,6 };
	Solution a;
	TreeNode * head = a.reConstructBinaryTree(l, r);
	return 0;
}