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
    ListNode* merge(ListNode* a, ListNode *b) {
        if (a == nullptr) return b;
        if (b == nullptr) return a;
        ListNode* result = nullptr;
        if (a->val > b->val) {
            result = b;
            b->next = merge(a, b->next);
        } else {
            result = a;
            a->next = merge(a->next, b);
        }
        return result;
    }
    
    ListNode* getMiddle(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = nullptr;
        while (fast && fast->next) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        prev->next = nullptr;
        return slow;
    }
    /*
        TC: O(n(merge) + nlogn(split))
        SC: O(logn) height of the tree for recurisve call stack
        Runtime: 84 ms, faster than 82.00% of C++ online submissions for Sort List.
        Memory Usage: 30.2 MB, less than 54.69% of C++ online submissions for Sort List.
    */
    ListNode* sortList(ListNode* head) {
        // already sorted case
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        auto mid = getMiddle(head);
        auto a = sortList(head);
        auto b = sortList(mid);
        return merge(a, b);
    }
};
