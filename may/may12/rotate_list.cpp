Problem Link: https://leetcode.com/problems/rotate-list/

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
    // TC: O(N)
    int length(ListNode* head) {
        int count = 0;
        while (head) {
            head = head->next;
            ++count;
        }
        return count;
    }
    // TC: O(N + N) N for calculating length and N for actual rotation
    ListNode* rotateRight(ListNode* head, int k) {
        // empty or have one node
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        int len = length(head);

        int actualRotationRequired = k % len;
        /*
            Understanding actualRotationRequired
            ex ->   2->0->1  and k = 4
                R1: 1->2->0
                R2: 0->1->2
                R3: 2->0->1
                R4: 1->2->0 which is equilvalent to R1 ie k % len
        */

        if (!actualRotationRequired) { return head; } // no change due to rotation
        ListNode* newTail = head;
        int moveNewTail = len - actualRotationRequired -1;
        while (moveNewTail) {
            newTail = newTail->next;
            --moveNewTail;
        }
        // new head
        ListNode* newHead = newTail->next;

        ListNode* oldTail = newHead; // move to old tail to set it to old head
        while (oldTail->next) {
            oldTail = oldTail->next;
        }
        oldTail->next = head;
        newTail->next = nullptr;
        return newHead;
    }
};
