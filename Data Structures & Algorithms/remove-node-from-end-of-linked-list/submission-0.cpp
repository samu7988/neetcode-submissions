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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = NULL;

        int i = 0;
        while(i < n)
        {
            fast = fast->next;
            i++;
        }
        while(fast != NULL)
        {
            prev = slow;
            slow= slow->next;
            fast = fast->next;

        }
        if(prev == NULL)  // If there is only node present in linked list .
        {
            head = head->next;
            free(slow);
            return head;
        }
        prev->next = slow->next;
        free(slow);
        return head;
    }
};
