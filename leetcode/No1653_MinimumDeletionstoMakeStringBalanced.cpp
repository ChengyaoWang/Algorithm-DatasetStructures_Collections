# include <string>
# include <vector>
# include <algorithm>

using namespace std;

class Solution {
public:
    int minimumDeletions(string s) {
        
        vector<int> l = {0}, r = {0};

        for (int i = 0; i < s.length(); ++i) {
            l.push_back(l.back() + s[i] == 'b');
            r.push_back(r.back() + s[s.length() - 1 - i] == 'a');
        }

        reverse(r.begin(), l.begin());
        int res = s.length();
        for (int i = 0; i <= s.length(); ++i) {
            res = min(res, l[i] + r[i]);
        }

        return res;        
    }
};