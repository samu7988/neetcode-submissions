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


// find middle of LL
// reverse second part of LL
// merge two parts of LL


class Solution {
public:
    void reorderList(ListNode* head) {
        if(head == NULL  || head->next == NULL)
        {
            return;
        }

        // middle of LL 

        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev_mid = NULL;

        while(fast != NULL && fast->next != NULL)
        {   
            prev_mid = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        prev_mid->next = NULL;

        // Reverse LL 
        ListNode* prev = NULL;
        ListNode* curr = slow;
        ListNode* front = NULL;

        while(curr != NULL)
        {
            front = curr->next;
            curr->next = prev;
            prev = curr;
            curr = front;
        }

        // Merge two LL

        ListNode* p = prev;
        ListNode* q  = head;
        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy;
        while(p != NULL && q != NULL)
        {
            temp->next = q;
            temp = temp->next;
            q = q->next;

            temp->next = p;
            temp = temp->next;
            p = p->next; 
        }
        if(p)
        {
            temp->next = p;
        }
        if(q)
        {
            temp->next = q;
        }

    }
};
