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
    // Apply BFS
    // Process each level one by one, get their sum and return the level which is minimum and has maximum level sum.
    /*
        Time Complexity: O(N) N - number of nodes
        Space Complexity: O(1)
        Runtime: 164 ms, Memory Usage: 107.4 MB
    */
    int maxLevelSum(TreeNode* root) {
        if (root == nullptr) return -1;
        std::queue<TreeNode*> q;
        q.push(root);
        int maxSum = INT_MIN; .// store the maximum sum of all level processed yet
        int level = 0;
        int minLevel; // our answer
        while (!q.empty()) {
            int n = q.size(); // n represents number of nodes at a level
            int sumOfEachLevel = 0; // store the sum of each level
            for (int i = 0; i < n; ++i) {
                TreeNode* t = q.front();
                q.pop();
                sumOfEachLevel += t->val;
                if (t->left) q.push(t->left);
                if (t->right) q.push(t->right);
            }
            if (maxSum/*maximum sum found yet*/ < sumOfEachLevel/*current level sum*/) {
                minLevel = level;
                maxSum = sumOfEachLevel;
            }
            ++level;
        }
        return minLevel+1; // first level is 1, so adding 1 in final result
    }
};
