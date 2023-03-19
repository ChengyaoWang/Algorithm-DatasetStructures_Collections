# include <vector>
using namespace std;

class Solution {
public:
    vector<int> mostVisited(int n, vector<int>& rounds) {
        int s = rounds.front(), e = rounds.back();
        bool flag = s > e;
        if (flag)   swap(s, e);

        auto cmp = [&](int a) {
            return (a == s) || (a == e) || (
                flag ^ (s <= a && a <= e)
            );
        };

        vector<int> ret = {};
        for (int i = 1; i <= n; ++i) {
            if (cmp(i))
                ret.push_back(i);
        }

        return ret;
    }
};