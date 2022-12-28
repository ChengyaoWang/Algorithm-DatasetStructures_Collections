struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:

    ListNode* findMidPoint(ListNode* head) {
        ListNode *fast = head, *slow = head;
        while (fast && fast -> next) {
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        return slow;
    }

    ListNode* reverseList(ListNode* head) {
        ListNode *prev = nullptr, *next = nullptr;
        while (head) {
            next = head -> next;
            head -> next = prev;
            prev = head;
            head = next;
        }
        return prev;
    }


    void reorderList(ListNode* head) {

        if (!(head -> next) || !(head -> next -> next)) {
            return ;
        }   

        auto midPoint = findMidPoint(head);
        auto end = reverseList(midPoint), start = head -> next;

        // Now Zip 2 Linked list Together
        for (int i = 0; start && end; ++i) {
            if (i % 2 == 0 || !start) {
                head -> next = end;
                end = end -> next;
            } else {
                head -> next = start;
                start = start -> next;
            }
            head = head -> next;
        }
    }
};