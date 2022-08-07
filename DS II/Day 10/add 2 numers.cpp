class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode sumHead(0), *p = &sumHead;    //define new node of listnode and the value is 0, get the address
        int nExtra = 0;       //as the carrry
        while(l1 || l2 || nExtra){
            int nSum = (l1? l1->val: 0) + (l2? l2->val: 0) + nExtra;
            nExtra = nSum / 10;   
            p->next = new ListNode(nSum % 10);      //creat a new node as the next of current p 
            p = p->next;

            l1= l1? l1->next :l1;
            l2= l2? l2->next :l2;
        }
        return sumHead.next;      
    }
};