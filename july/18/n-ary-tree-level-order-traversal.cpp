/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    /// Applying BFS
    /*
        Time Complexity: O(N) where N is number of nodes in a tree
        Space Complexity: O(N) 
        Runtime: 20ms, Space: 11.8MB
    */
    vector<vector<int>> levelOrder(Node* root) {
        if (root == nullptr) return {};
        
        /* answerto return */ std::vector<std::vector<int>> LOT; // LOT- level order traversal
        std::queue<Node*> q;
        q.push(root);
        while (!q.empty()) {
            int size = q.size(); // number of nodes in a level
            std::vector<int> eachLevel; 
            while (size) { // parsing a level at once
                Node* t = q.front();
                eachLevel.push_back(t->val);
                q.pop();
                /*
                 *  In case of simple level order traversal of binary tree what we do is:
                 *     if (root-left) q.push(root->left)
                 *     if (root->right) q.push(root->right)
                 *
                 * But here instead of two children (left and right) the tree has N children so we need to iterate over each of them and add them in queue
                 * */
                // iterate over the child of each node for N-ary tree
                for (auto child: t->children) {
                    q.push(child);
                }
                --size;
            }
            LOT.push_back(eachLevel);
            
        }
        return LOT;
    }
};
