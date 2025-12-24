# include <vector>
# include <unordered_map>
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
    ListNode* removeZeroSumSublists(ListNode* head) {
        
        ListNode* dummy = new ListNode(-1e7, head);

        int cumSum = 0;
        unordered_map<int, ListNode*> mem;
        vector<int> cumStack = {};

        for (auto p = dummy; p != nullptr; p = p -> next) {
            cumSum += p -> val;
            if (mem.find(cumSum) != mem.end()) {
                mem[cumSum] -> next = p -> next;
                while(cumStack.back() != cumSum) {
                    auto elem = cumStack.back();
                    cumStack.pop_back();
                    mem.erase(elem);
                }
            } else {
                mem.insert(make_pair(cumSum, p));
                cumStack.push_back(cumSum);
            }
        }

        return dummy -> next;
    }
};