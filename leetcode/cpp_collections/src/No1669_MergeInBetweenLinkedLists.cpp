struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode *l1_a = nullptr, *l1_b = nullptr;
        ListNode *p = nullptr;

        int cnter = 0;
        for (p = list1; p != nullptr; p = p -> next) {
            if (cnter == (a - 1)) {
                l1_a = p;
            } else if (cnter == b) {
                l1_b = p;
            }
            ++cnter;
        }

        // Get Final Node of list2
        ListNode *l2_a = list2, *l2_b = nullptr;
        for (l2_b = list2; l2_b -> next != nullptr; l2_b = l2_b -> next) {}

        l1_a -> next = l2_a;
        l2_b -> next = l1_b -> next;
        return list1;
    }
};