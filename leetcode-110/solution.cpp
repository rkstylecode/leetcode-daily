class Solution {
public:
    bool ans = true;
    int dfs(TreeNode* node, int d){
        if(!node || !ans){
            return 0;
        }

        int leftDepth = dfs(node->left, d+1);
        int rightDepth = dfs(node->right, d+1);

        if(abs(leftDepth-rightDepth)>1){
            ans = false;
        }
        return 1 + max(leftDepth, rightDepth);
    }

    bool isBalanced(TreeNode* root) {
        dfs(root, 0);
        return ans;
    }
};