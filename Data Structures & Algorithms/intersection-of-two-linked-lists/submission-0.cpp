class Solution {
public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        
        if (!headA || !headB) return NULL;
        
        unordered_map<ListNode*, bool> visited;          // node → seen flag
        
        // ── Pass 1: mark all nodes of A as seen ──
        ListNode* curr = headA;
        while (curr) {
            visited[curr] = true;                        // record node's address
            curr = curr->next;
        }
        
        // ── Pass 2: check B — first shared address is the intersection ──
        curr = headB;
        while (curr) {
            if (visited.find(curr) != visited.end())     // node exists in map
                return curr;                              // → intersection found
            curr = curr->next;
        }
        
        return NULL;                                      // no intersection
    }
};