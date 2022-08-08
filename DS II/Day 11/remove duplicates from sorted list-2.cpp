class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* dummy_head = new ListNode(0, head);
        ListNode* prev = dummy_head;
        
        while (head) {
            if (head->next && head->val == head->next->val) {
                ListNode* del_start = head;
                while (head->next && head->val == head->next->val)
                    head = head->next;
                ListNode* del_end = head->next;
                
                prev->next = head->next;
                head = prev;
                
                while (del_start != del_end) {
                    ListNode *tmp = del_start;
                    del_start = del_start->next;
                    delete tmp;
                }
            } else
                prev = prev->next;
            
            head = head->next;
        }
        
        return dummy_head->next;
    }
};