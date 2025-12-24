# include <limits>
# include <algorithm>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution {
public:
    int pairSum(ListNode* head) {
        // Achieving O(n) space by reversing the list
        ListNode *p_fast = head -> next, *p_slow = head;
        while (p_fast != nullptr && p_fast -> next != nullptr) {
            p_fast = p_fast -> next -> next;
            p_slow = p_slow -> next;
        }
        
        // Reverse the list
        ListNode* pp = p_slow -> next, *ppp;
        p_slow -> next = nullptr;
        p_slow = pp -> next;
        while (p_slow != nullptr) {
            ppp = p_slow -> next;
            p_slow -> next = pp;
            pp = p_slow;
            p_slow = ppp;
        }

        // Count Max
        p_fast = head;
        p_slow = pp;

        int retVal = std::numeric_limits<int>::min();
        while (p_fast != nullptr) {
            retVal = std::max(retVal, p_slow -> val + p_fast -> val);
            p_fast = p_fast -> next;
            p_slow = p_slow -> next;
        }

        return retVal;
    }
};