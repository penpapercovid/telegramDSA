// Problem: https://leetcode.com/problems/validate-binary-search-tree/
// The Tree can also have duplicates.

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
// To run in other platform include libraries yourself.
class Solution {
public:
    // Helper function
    void inorderTraversal(TreeNode* root, std::vector<int> &inorder) {
        if (root == nullptr) {
            return;
        }
        inorderTraversal(root->left, inorder);
        inorder.push_back(root->val);
        inorderTraversal(root->right, inorder);
    }

    // Helper function
    // static because calling funtion without creating object in later steps.
    static bool comparator(const int &a, const int &b) {
        return a <= b;
        // considering = in case when BST has duplicates e.g-> [1, 1] Not a BST
    }

    // ------------------------------------------------------------------
    // Method 1: Using the fact that inorder of the BST is always sorted
    // ------------------------------------------------------------------

    // TC: O(N + N) for visiting the every node of the tree + for checking if array is sorted
    // SC: O(N(vector space for storing node of the tree) + (N for functional stack if considered))
    bool isValidBST(TreeNode* root) {
        if (root == nullptr) {
            return true;
        }
        std::vector<int> inorder;
        inorderTraversal(root, inorder);
        return std::is_sorted(inorder.begin(), inorder.end(), /*a lambda used to sort the vector based on condition like asc, des, etc*/ comparator);
    }


    // Helper
    // return the max value in left subtree
    int maxOfLeftSubTree(TreeNode* node) {
        if (node == nullptr) {
            return INT_MIN;
        }
        int left = maxOfLeftSubTree(node->left);
        int right = maxOfLeftSubTree(node->right);
        // max of all three values
        return std::max(node->val, std::max(left, right));
    }
    
    // return the min value in right subtree
    int minOfRightSubTree(TreeNode* node) {
        if (node == nullptr) {
            return INT_MAX;
        }
        int left = minOfRightSubTree(node->left);
        int right = minOfRightSubTree(node->right);
        // min of all three values
        return std::min(node->val, std::min(left, right));
    }
    
    
    
    // ------------------------------------------------------------------
    // Method 2: Using the fact that in BST root of node is greater than all of its left subtree and lesser than of its right subtree. This must be true for left and right subtree as well
    // ------------------------------------------------------------------

    // TC: O(N^2) for each node we are traversing the tree to calculate max and min
    // SC: O(N^2) 
    bool isValidBST(TreeNode* root) {
        if (root == nullptr) {
            return true;
        }
        if (root->left && root->val <= maxOfLeftSubTree(root->left)) {
            return false;
        }
        if (root->right && root->val >= minOfRightSubTree(root->right)) {
            return false;
        }
        // to be a BST the left and right subtree must be a BST.
        return isValidBST(root->left) && isValidBST(root->right);

    }
    
    // Helper Function
   bool isValidBST(TreeNode *root, int min, int max) {
       if (root == nullptr) {
           return true;
       }
       if (root->val < min || root->val > max) {
           return false;
       }
       return isValidBST(root->left, INT_MIN, root->val-1) /*left subtree can have value between [INT_MIN, X-1]*/
                 &&
              isValidBST(root->right, root->val+1, INT_MAX); /*right subtree can have value between [X+1, INT_MAX]*/
   }

    // ------------------------------------------------------------------
    // Method 3: Using the fact that if root value is X then left subtree can have all values from [INT_MIN, X-1] and the right subtree can have [X+1, INT_MAX].
    // ------------------------------------------------------------------
    
    // TC: O(N) for visting each node of the tree
    // SC: O(N) for functional stack
    // -----------------------------------------------------------------------------
    // Code is BUGGY when root is INT_MIN or INT_MAX, so do not rely on this method.
    // -----------------------------------------------------------------------------
    bool isValidBST(TreeNode* root) {
        return isValidBST(root, INT_MIN, INT_MAX);
    }

    
    // Helper for Method 4
    // Do the inorder traversal and compare between curr node and prev node at each node.
    bool isValidBST(TreeNode* root, TreeNode* &prev) {
        if (root == nullptr) {
            return true;
        }
        // going left and validating
        if (!isValidBST(root->left, prev)) {
            return false;
        }
        // prev is not null 
        // = to handle dup(s)
        if (prev && prev->val >= root->val) {
          return false;
        }
        prev = root;
       
        // going right and validating
        if (!isValidBST(root->right, prev)) {
            return false;
        }
        return true;
    }

    // ------------------------------------------------------------------
    // Method 4: Using the previous node pointer and doing the inorder traversal. As inorder is sorted the previous node must not be greater than curr node in processing.
    // ------------------------------------------------------------------
    
    // TC: O(N)
    // SC: O(N)
    bool isValidBST(TreeNode* root) {
        TreeNode* prev = nullptr;
        return isValidBST(root, prev);
    }
};

// Most Optimal and Correct: Method-4
