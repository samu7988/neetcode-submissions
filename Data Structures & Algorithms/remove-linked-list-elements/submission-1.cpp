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
    ListNode* removeElements(ListNode* head, int val) {
        if(head == NULL)
        {
            return NULL;
        }
        ListNode* dummy = new ListNode();
        dummy->val = -1;
        dummy->next = head;

        ListNode* temp = head;
        ListNode* prev = dummy;
        while(temp)
        {   
            
            if(temp->val == val)
            {
                prev->next = temp->next;
                delete temp;
                temp = prev->next;
            }
            else
            {
                prev = temp;
                temp = temp->next;
            }
        }
        return dummy->next;

    }
};