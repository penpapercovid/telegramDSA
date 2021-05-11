Problem Link: https://leetcode.com/problems/remove-nth-node-from-end-of-list/


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
------------------------------------------------------------------------------------------------------------  
    /*
      Method 1:
      1. Find the length of the list.
      2. Check if length == n handle head deletion case.
      3. Else, the nth node from end will be (len - n + 1)th node from start.

      TC: O(N + N)
      SC: O(1)
    */
------------------------------------------------------------------------------------------------------------  

------------------------------------------------------------------------------------------------------------
    // Method 2: Using Recursion
    // TC: O(N)
    // SC: O(1) or O(N) if functional stack is considered
    ListNode* removeNthFromEndUtil(ListNode* head, int n, int i) {
        if (head == nullptr) {
            return nullptr;
        }
        head->next = removeNthFromEndUtil(head->next, n, i);
        if (++i == n) {
            ListNode* t = head->next;
            delete head;
            return t;
        }
        return head;
       
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        return removeNthFromEndUtil(head, n, 1);
    }
------------------------------------------------------------------------------------------------------------  
};
