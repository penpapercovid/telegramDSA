/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    /*  Utility to get level of a node from bottom up level
                          3(4<-level)
                        /     \
                     5(3)      1(2)
                  /   \      /  \ 
                6(1)   2(2) 0(1) 8(1)
                      /  \
                     7(1) 4(1)
                 
        int f(TreeNode* root) {
        if (root == nullptr) return 0;
        int leftLevel = f(root->left);
        int rightLevel = f(root->right);
        std::cout << "level of " << root->val << " is: " << 1 + std::max(leftLevel, rightLevel) << std::endl;
        return 1 + std::max(leftLevel, rightLevel);
    }
    */
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        return lcaDeepestLeavesUtil(root).first;
    }
    
    std::pair<TreeNode*, int/*level info*/> lcaDeepestLeavesUtil(TreeNode* root) {
        if (root == nullptr) return {root, 0};
        auto leftLevel = lcaDeepestLeavesUtil(root->left);
        auto rightLevel = lcaDeepestLeavesUtil(root->right);
        // if left and right level are same that means root is the LCA
        if (leftLevel.second == rightLevel.second) return {root, leftLevel.second+1};
        // if left > right level that means LCA lies in left
        if (leftLevel.second > rightLevel.second) return {leftLevel.first, leftLevel.second+1};
        // else right
        else return {rightLevel.first, rightLevel.second+1};
    }
};
