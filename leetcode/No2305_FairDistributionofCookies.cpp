# include <vector>
# include <algorithm>
# include <unordered_set>

using namespace std;

class Solution {
public:
    int distributeCookies(vector<int>& cookies, int k) {
        vector<int> slot(k, 0);
        unordered_set<int> unSeen = {};
        for (int i = 0; i < k; ++i)     unSeen.insert(i);
        return dfsHelper(0, k, unSeen, slot, cookies);
    }

    int dfsHelper(
        int depth,
        int totalK,
        unordered_set<int>& unSeen,
        vector<int>& slot,
        vector<int> cookies
    ) {
        // Max Depth Reached
        if (depth == cookies.size()) {
            return *max_element(slot.begin(), slot.end());
        } 

        auto res = INT_MAX;
        // We Need At Least One for each kid
        if (cookies.size() - depth == unSeen.size()) {
            auto elem = *unSeen.begin();
            unSeen.erase(elem);
            slot[elem] += cookies[depth];
            res = dfsHelper(depth + 1, totalK, unSeen, slot, cookies);
            slot[elem] -= cookies[depth];
        } else {
            for (int i = 0; i < totalK; ++i) {
                unSeen.erase(i);
                slot[i] += cookies[depth];
                res = min(res, dfsHelper(depth + 1, totalK, unSeen, slot, cookies));
                slot[i] -= cookies[depth];
            }
        }

        return res;
    }
};