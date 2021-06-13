Problem Link: https://leetcode.com/problems/range-sum-of-bst/


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
    // Time Complexity : O(h) where h could be as worse as n
    // SC: O(h) for functional Stack
    // Method 1
    int rangeSumBST(TreeNode* root, int low, int high) {
        if (root == nullptr) {
            return 0;
        }
        if (root->val < low) { // ignore left
            return rangeSumBST(root->right, low, high);
        }
        if (root->val > high) { //ignore right
            return rangeSumBST(root->left, low, high);
        }

        return root->val + rangeSumBST(root->left, low, high) + rangeSumBST(root->right, low, high);
    }
    // Method 2
    // TC: O(N)
    // SC: O(N) for functional Stack
    int rangeSumBST(TreeNode* root, int low, int high) {
        if (root == nullptr) {
            return 0;
        }
        int sum = 0;
        sum += rangeSumBST(root->left, low, high);
        sum += rangeSumBST(root->right, low, high);
        if (root->val >= low && root->val <= high) sum += root->val;
        return sum;
    }
};
