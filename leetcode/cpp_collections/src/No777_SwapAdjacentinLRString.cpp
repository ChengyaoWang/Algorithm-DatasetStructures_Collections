# include <string>
# include <vector>
using namespace std;

class Solution {
public:
    bool canTransform(string start, string end) {

        vector<pair<char, int>> st, en;
        int n = start.size();
        for (int i = 0; i < n; ++i) {
            if (start[i] != 'X')    st.push_back({start[i], i});
            if (end[i] != 'X')      en.push_back({end[i], i});
        }
        if (st.size() != en.size()) return false;
        for (int i = 0; i < st.size(); ++i) {
            if (st[i].first != en[i].first)
                return false;
            auto c = st[i].first;
            if (c == 'L' && st[i].second < en[i].second)
                return false;
            if (c == 'R' && st[i].second > en[i].second)
                return false;
        }
        return true;
    }
};