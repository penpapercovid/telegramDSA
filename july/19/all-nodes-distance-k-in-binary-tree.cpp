/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void distanceKDown(TreeNode* root, int k, std::vector<int> &res) {
        if (root == nullptr) return;
        
        if (k == 0) {
            res.push_back(root->val);
            return;
        }
                
        distanceKDown(root->left, k-1, res);
        distanceKDown(root->right, k-1, res);
    }
    
    int distanceK(TreeNode* root, TreeNode* target, int k, std::vector<int> &res) {
        if (root == nullptr) return 0;
        if (root == target) {
            distanceKDown(root, k, res); // printing the node at k distnace from target(downward direction)
            return 1; // significance -> found the target
        }
        int ld = distanceK(root->left, target, k, res);
        if (ld != 0) {
            if (ld == k) res.push_back(root->val); // for k = 1 distance from target
            else distanceKDown(root->right, k-ld-1, res); // we are at one step up from target so going right will decrement k by 1 ie why (k -ld -1). Here -1 signify that we are going one step down on right that will increase the distance by 1
            return ld+1; // return +1 because at each step upward the distnace is going to increase by 1 from target
        }
        
        int rd = distanceK(root->right, target, k, res);
        if (rd != 0) {
            if (rd == k) res.push_back(root->val);
            else distanceKDown(root->left, k-rd-1, res);
            return rd+1;
        }
        
        return 0;
    }
    /*
        Recursive Solution
        Time Complexity: O(N)
        Space Complexity: O(N)
    */
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        if (root == nullptr || target == nullptr) return {};
        
        std::vector<int> res;
        distanceK(root, target, k, res);
        return res;
    }
};
