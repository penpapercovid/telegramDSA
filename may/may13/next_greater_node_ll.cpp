/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    
    // Brute Force
    /*
        1. Calculate the max for each node in the list.
        2. Put in result vector, return it.
        3. TC: O(N^2)
        4. SC: O(1)
        Code:
            curr = head;
            vector res;
            while (curr) {
                nextMax = curr->next;
                int NGE = 0;
                while (nextMax) {
                    NGE = std::max(NGE, nextMax->val);
                    nextMax = nextMax->next;
                }
                res.push_back(NGE);
                curr = curr->next;
            }

            return res;
    */
    
    
    // Method 1: Convert List into Array
    // TC: O(N) -> number of total push is N  so pop will be N. 
    vector<int> nextLargerNodes(ListNode* head) {
       if (head == nullptr) {
            return {};
        }
        //coverting to list
        std::vector<int> res;
        for (; head; head = head->next) res.push_back(head->val);
        
        std::stack<int> s;
        for (int i = res.size() -1; i >= 0; --i) {
            int val = res[i];
            while (!s.empty() && s.top() <= res[i]) s.pop();
            res[i] = s.empty() ? 0 : s.top();
            s.push(val);
        }

        return res;

        
    }
};
