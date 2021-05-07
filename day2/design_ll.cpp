// Problem Link: https://leetcode.com/problems/design-linked-list/

class MyLinkedList {
public:
    /** Initialize your data structure here. */
    MyLinkedList() : m_head(nullptr), m_tail(nullptr), m_size(0) {
        
    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    ------------------------------------------------------------------------------------------------------
    // TC: O(N) 
    // can put some extra check for head, tail and return in O(1).
    -----------------------------------------------------------------------------------------------------
    int get(int index) {
        if (index < 0 || index >= m_size) {
            return -1;
        }
        ListNode *t = m_head;
        while (index) {
            --index;
            t = t->next;
        }
        return t ? t->val : -1;
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    ------------------------------------------------------------------------------------------------------
        // TC: O(1)
    ------------------------------------------------------------------------------------------------------
    void addAtHead(int val) {
        ListNode *node = new ListNode(val);
        // list is empty
        if (m_head == nullptr) {
            m_head = m_tail = node;
        } else {
            node->next = m_head;
            m_head = node;
        }
        ++m_size;
    }
    
    /** Append a node of value val to the last element of the linked list. */
    ------------------------------------------------------------------------------------------------------
        // TC: O(1)
    ------------------------------------------------------------------------------------------------------
    void addAtTail(int val) {
        ListNode *node = new ListNode(val);
        // list is empty
        if (m_tail == nullptr) {
            m_head = m_tail = node;
        } else {
            m_tail->next = node;
            m_tail = m_tail->next;
        }
        ++m_size;
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    ------------------------------------------------------------------------------------------------------
        // TC: O(N)
    ------------------------------------------------------------------------------------------------------
    void addAtIndex(int index, int val) {
        if (index < 0 || index > m_size) { // list -> [1,2] , m_size = 2 we can insert at index 2 not beyond that.
            return;
        }
        // Insertion will happen either
        // a. insert at head (m_head will be modifed)
        // b. insert at tail (m_tail will be modified)
        // c. insert in mid (m_head and m_tail won't be affected)
        
        // case a at head
        if (index == 0) {
            addAtHead(val);
        } else if (index == m_size) { // case b at tail
            addAtTail(val);
        } else { // case c in mid
            ListNode *curr = m_head;
            ListNode *prev = m_head;
            while (index) {
                prev = curr;
                curr = curr->next;
                --index;
            }
            // create Node
            ListNode *node = new ListNode(val);
            node->next = curr;
            prev->next = node;
             ++m_size;
        }       
    } 
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    ------------------------------------------------------------------------------------------------------
        // TC: O(N)
    ------------------------------------------------------------------------------------------------------
    void deleteAtIndex(int index) {
        if (index < 0 || index >= m_size) { // list -> [1,2] , m_size = 2 we can delete at index <= 1 not beyond that.
            return;
        }
        // Deletion will happen either
        // a. delete at head (m_head will be modifed , m_tail will be modifed in case of one element)
        // b. delete at tail (m_tail will be modified, m_head in case of one element)
        // c. delete in mid (m_head and m_tail won't be affected)
        
        ListNode *curr = m_head;
        // case a at head
        if (index == 0) {
            m_head = m_head->next;
            if (m_size == 1) { m_tail = m_tail->next; } // only one item list
            delete curr;
        } else if (index == (m_size-1)) { // case b at tail
            // move curr to second last item in the list
            while (curr->next != m_tail) {
                curr = curr->next;
            }
            delete m_tail; // delete m_tail
            m_tail = curr;
        } else { // case c delete in between
            ListNode *prev = nullptr;
            while (index) {
                --index;
                prev = curr;
                curr = curr->next;
            }
            ListNode *nodeToDel = curr;
            prev->next = curr->next;
            delete nodeToDel;
        }     
        --m_size;
    }
private:
    ListNode *m_head; // pointing to start of the list
    ListNode *m_tail; // pointing to end of the list
    int m_size;
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
