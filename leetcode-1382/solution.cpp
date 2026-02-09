class Solution {
public:
    void inOrderTraversal(TreeNode* node, vector<TreeNode*>& sortedNodes){
        if(!node) return;

        inOrderTraversal(node->left, sortedNodes);
        sortedNodes.push_back(node);
        inOrderTraversal(node->right, sortedNodes);
    }

    TreeNode* buildBST(int left, int right, vector<TreeNode*>& sortedNodes){
        if(left>right){
            return nullptr;
        }

        int mid = left + (right - left)/2;
        
        TreeNode* root = sortedNodes[mid];
        root->left = buildBST(left, mid-1, sortedNodes);
        root->right = buildBST(mid+1, right, sortedNodes);

        return root;
    }

    TreeNode* balanceBST(TreeNode* root) {
        vector<TreeNode*> sortedNodes;
        inOrderTraversal(root, sortedNodes);

        int n = sortedNodes.size();
        return buildBST(0, n-1, sortedNodes);
    }
};