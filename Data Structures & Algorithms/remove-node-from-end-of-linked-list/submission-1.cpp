class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        if (head == NULL) return NULL;                    // ✅ handle empty list
        
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = NULL;

        // Phase 1: move fast n steps ahead
        for (int i = 0; i < n && fast != NULL; i++)       // ✅ NULL-safe
            fast = fast->next;

        // Phase 2: walk together until fast hits end
        while (fast != NULL)
        {
            prev = slow;
            slow = slow->next;
            fast = fast->next;
        }
        
        // Phase 3: unlink the target
        if (prev == NULL)                                  // ✅ target is the head
        {
            head = head->next;
            delete slow;                                   // ✅ delete (not free)
            return head;
        }
        
        prev->next = slow->next;
        delete slow;                                       // ✅ delete (not free)
        return head;
    }
};