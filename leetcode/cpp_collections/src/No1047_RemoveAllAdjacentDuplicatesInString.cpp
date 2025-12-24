# include <deque>
# include <string>
using namespace std;

class Solution {
public:
    string removeDuplicates(string s) {
        
        deque<pair<char, bool>> q = {};
        for (auto c: s) {
            while (!q.empty() && q.back().second) {
                q.pop_back();
            }
            if (!q.empty() && q.back().first == c) {
                q.back().second |= true;
                continue;
            }
            q.emplace_back(c, false);
        }

        string ret = "";
        while (!q.empty()) {
            auto elem = q.front();
            q.pop_front();
            if (!elem.second)
                ret.push_back(elem.first);
        }
        return ret;
    }
};