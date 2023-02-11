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
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> ret(10001, 0);
        vector<pair<int, int>> s = {};
        int i = 0;
        for (auto p = head; p != nullptr; p = p -> next) {
            while (!s.empty() && s.back().first < p -> val) {
                auto elem = s.back();
                s.pop_back();
                ret[elem.second] = p -> val;
            }

            s.push_back({p -> val, i});
            ++i;
        }
        
        ret.resize(i);
        return ret;
    }
};