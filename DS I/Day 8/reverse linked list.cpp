class Solution {
public:
    ListNode* reverseList(ListNode* head) {        
        ListNode *aNode = head;
        ListNode *aPrev = NULL;
        ListNode *aNext = NULL;
        while (aNode != NULL) {
            aNext = aNode->next;
            aNode->next = aPrev;
            aPrev = aNode;
            aNode = aNext;    
        }
        return aPrev;
        
    }
};
