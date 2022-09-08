# include <vector>
# include <algorithm>

using namespace std; 

class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        vector<int> s = {};
        vector<int> res = {};

        for (auto i = heights.rbegin(); i != heights.rend(); ++i) {
            auto cnt = 0;
            while (!s.empty() && (*i) > s.back()) {
                s.pop_back();
                ++cnt;
            }

            res.push_back(cnt + s.empty());
            s.push_back(*i);
        }

        reverse(res.begin(), res.end());
        return res;
    }
};