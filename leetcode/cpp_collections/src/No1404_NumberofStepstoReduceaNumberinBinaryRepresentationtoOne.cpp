# include <string>
using namespace std;

class Solution {
public:
    int numSteps(string s) {
        int cnt = 0;

        while (s.size() > 1) {
            
            if (s.back() == '0') {
                s.pop_back();
                ++cnt;
            } else {
                while (!s.empty() && s.back() == '1') {
                    s.pop_back();
                    ++cnt;
                }
                if (s.empty()) {
                    s.push_back('1');
                } else {
                    s.back() = '1';
                }
                ++cnt;
            }
        }

        return cnt;
    }
};