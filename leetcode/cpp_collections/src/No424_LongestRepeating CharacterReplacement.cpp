# include <string>
# include <vector>
using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {
        int ret = 0;
        vector<int> cnter(26);
        int slow = 0;
        for (int i = 0; i < s.size(); ++i) {
            ++cnter[s[i] - 'A'];
            auto maxElem = *max_element(cnter.begin(), cnter.end());
            while (i - slow + 1 - maxElem > k) {
                --cnter[s[slow++] - 'A'];
            } 
            ret = max(ret, i - slow + 1);
        }
        return ret;        
    }
};