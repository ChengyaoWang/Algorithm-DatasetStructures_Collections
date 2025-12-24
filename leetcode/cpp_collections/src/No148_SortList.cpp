# include <utility>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    
    ListNode* sortList(ListNode* head) {

        if (head == nullptr || head -> next == nullptr) {
            return head;
        }
        
        ListNode *lo = head, *hi = head;
        while (hi -> next && hi -> next -> next) {
            lo = lo -> next;
            hi = hi -> next -> next;
        }

        auto tmp = lo -> next;
        lo -> next = nullptr;
        ListNode *l = sortList(head), *r = sortList(tmp);

        ListNode *dummy = new ListNode();
        ListNode *p = dummy;

        while (l && r) {
            if (l -> val < r -> val) {
                p -> next = l;
                l = l -> next;
            } else {
                p -> next = r;
                r = r -> next;
            }
            p = p -> next;
        }
        if (l)  p -> next = l;
        if (r)  p -> next = r;

        return dummy -> next;
    }
};