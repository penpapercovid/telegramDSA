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
    int sizeOfTree(TreeNode* root) {
        if (root == nullptr) return 0;
        return 1 + sizeOfTree(root->left) + sizeOfTree(root->right);
    }
    
    bool isCompleteTreeUtil(TreeNode* root, int level, int n) {
        if (root == nullptr) return true;
        if (level >= n) return false;
        return isCompleteTreeUtil(root->left, 2*level+1, n)
                    &&
               isCompleteTreeUtil(root->right, 2*level+2, n);
    }
    // Recursive Solution - Using DFS
    // Time Complexity: O(n+n) -> O(n), visiting the nodes two times
    // Space Complexity: O(H), where H is height of complete binary tree (H = ceil(log2N + 1) -1)
    
    /*
        Runtime: 4 ms, Memory Usage: 10.1 MB
    */
    bool isCompleteTree(TreeNode* root) {
        int n = sizeOfTree(root);
        return isCompleteTreeUtil(root, 0, n);
    }
    
    
    
    // Iterative Solution - Using BFS
    /*
        Time Complexity: O(n), single iteration
        Space Complexity: O(n)
    */
    bool isCompleteTree(TreeNode* root) {
        if (root == nullptr) return true;
        std::queue<TreeNode*> q;
        q.push(root);
        bool leftChildNull = false;
        bool rightChildNull = false;
        while (!q.empty()) {
            TreeNode* t = q.front();
            q.pop();
            if (t->left) {
                if (rightChildNull) return false;
                q.push(t->left);
            }
            else leftChildNull = true;
            
            if (t->right) {
              if (leftChildNull) return false;
              q.push(t->right);  
            } 
            else rightChildNull = true;
        }
        
        return true;
    }
    
};
