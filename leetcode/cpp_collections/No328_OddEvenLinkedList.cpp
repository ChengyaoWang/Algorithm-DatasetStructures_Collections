struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {

        ListNode* odd = new ListNode();
        ListNode* even = new ListNode();
        ListNode *odd_st = odd, *even_st = even;
        
        ListNode *p = head, *pn = nullptr;
        
        int i = 0;
        while (p != nullptr) {
            pn = p -> next;
            p -> next = nullptr;
            
            if ((i & 1) == 0) {
                odd_st -> next = p;
                odd_st = p;
            } else {
                even_st -> next = p;
                even_st = p;
            }
                
            p = pn;
            ++i;
        }

        odd_st -> next = even -> next;
        return odd -> next;
    }
};