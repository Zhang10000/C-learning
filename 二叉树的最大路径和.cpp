class Solution {
public:
    int ans = INT_MIN;
    int helper(TreeNode* root){
        if(root == nullptr) return 0;
        int leftSum = helper(root->left);
        int rightSum = helper(root->right);
        int nodeVal = max(max(root->val + leftSum, root->val + rightSum), 0);
        int newRoot = root->val + leftSum + rightSum;
        //cout << leftSum << "--" << rightSum << "--" << newRoot << endl;
        ans = max(ans, newRoot);
        return nodeVal;
    } 
    int maxPathSum(TreeNode* root) {
        if(root == nullptr) return 0;
        helper(root);
        return ans;
    }
};
