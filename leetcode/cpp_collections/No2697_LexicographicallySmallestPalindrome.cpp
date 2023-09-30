# include <string>
using namespace std;

class Solution {
public:
    string makeSmallestPalindrome(string s) {
        
        int i = 0, j = s.size() - 1;
        while (i < j) {
            auto c = min(s[i], s[j]);
            s[i++] = c;
            s[j--] = c;
        }

        return s;
    }
};