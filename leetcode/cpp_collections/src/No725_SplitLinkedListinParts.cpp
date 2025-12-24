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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {

        int len = 0;
        for (auto p = head; p != nullptr; p = p -> next) {
            ++len;
        }

        int seg = len / k, remainder = len % k;
        auto p = head;
        vector<ListNode*> ret = {};
        for (int i = 0; i < k; ++i) {
            ret.push_back(p);
            if (p == nullptr) {
                continue;
            }
            auto l = seg + (remainder > 0);
            for (int j = 0; j < l; ++j) {
                p = p -> next;
            }

            --remainder;
            auto tmp = p -> next;
            p -> next = nullptr;
        }

        return ret;
    }
};