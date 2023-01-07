# include <vector>
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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* p = head;
        int len = 0;
        for (ListNode* p = head; p; p = p -> next) {
            ++len;
        }

        int i = 0;
        ListNode* a[2] = {nullptr, nullptr};
        for (ListNode* p = head; p; p = p -> next) {
            if (i == k - 1) a[0] = p;
            if (i == len - k) a[1] = p;
            ++i;
        }
        swap(a[0] -> val, a[1] -> val);

        return head;
    }
};