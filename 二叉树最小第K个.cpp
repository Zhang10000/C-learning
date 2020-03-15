class Solution {
public:
    int count = 0;
    TreeNode* KthNode(TreeNode* pRoot, int k) {
        if(pRoot){
            TreeNode* node = KthNode(pRoot->left,k);
            if(node) return node;
            count++;
            if(count == k) return pRoot;
            if(node = KthNode(pRoot->right,k)) return node;
        }
        return nullptr;
    }
};
