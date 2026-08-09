class Solution {
public:
    bool isPalindrome(ListNode* head) {
        
        if (head == NULL || head->next == NULL) return true;      // ✅ edge case
        
        // ── Step 1: Find middle using slow/fast pointers ──
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev_slow = NULL;
        ListNode* first = head;
        
        while (fast != NULL && fast->next != NULL) {
            prev_slow = slow;                            // ✅ consistent name
            slow = slow->next;
            fast = fast->next->next;
        }
        
        prev_slow->next = NULL;                          // split into two halves
        
        // ── Step 2: Reverse second half (starting from slow) ──
        ListNode* temp = slow;
        ListNode* prev = NULL;
        ListNode* front = NULL;
        
        while (temp != NULL) {
            front = temp->next;
            temp->next = prev;
            prev = temp;
            temp = front;
        }
        
        // ── Step 3: Compare first half with reversed second half ──
        while (first && prev) {
            if (first->val != prev->val) return false;
            first = first->next;
            prev = prev->next;
        }
        
        return true;
    }
};