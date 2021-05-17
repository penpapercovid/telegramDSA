Problem Link: https://leetcode.com/problems/partition-list/


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
    /*
        Algo: Create Two Dummy List such that all value greater than x goes to one list and all values smaller than x goes to
                other list

            ListNode* before_x = new ListNode(0);
            ListNode* after_x =  new ListNode(0);
            If (x > head->val)
                goes left
            Else
                goes right

    */
    // TC: O(N)
    // SC: O(1)
    ListNode* partition(ListNode* head, int x) {
        if (head == nullptr) {
            return nullptr;
        }

        ListNode* before_x = new ListNode(0);
        ListNode* before = before_x;
        ListNode* after_x = new ListNode(0);
        ListNode* after = after_x;

        while (head != nullptr) {
            if (x > head->val) { // it will go into before x list because all values less than x will be on left side of x.
                before->next = head;
                before = before->next;
            } else {
                after->next = head;
                after = after->next;
            }
            head = head->next;
        }

        before->next = after_x->next;
        after->next = nullptr;
        return before_x->next;

    }
};

