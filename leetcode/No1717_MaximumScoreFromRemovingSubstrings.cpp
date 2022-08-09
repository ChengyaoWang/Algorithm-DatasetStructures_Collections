# include <vector>
# include <string>
# include <unordered_map>

using namespace std;

class Solution {
public:
    int maximumGain(string s, int x, int y) {
        char a = 'a', b = 'b';
        if (y > x) {
            swap(a, b);
            swap(x, y);
        }

        int ans = 0;
        vector<int> cnter(2, 0);
        s.push_back('x');

        for (auto &i: s) {
            if (i == a || i == b) {
                if (i == b && cnter[a - 'a'] > 0) {
                    ans += x;
                    --cnter[a - 'a'];
                } else {
                    ++cnter[i - 'a'];
                }
            } else {
                ans += y * min(cnter[a - 'a'], cnter[b - 'a']);
                cnter.clear();
            }
        }
        
        return ans;
    }
};