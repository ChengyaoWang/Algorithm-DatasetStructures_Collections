# include <string>
using namespace std;

class Solution {
public:

    bool matches(const char a, const char b) {
        return (a == b) || (a == (b + 1)) || (a == 'a' && b == 'z');
    }

    bool canMakeSubsequence(string str1, string str2) {
        
        int p = 0;
        for (auto& i: str1) {
            if (matches(i, str2[p])) {
                ++p;
            }
            if (p == str2.size()) {
                return true;
            }
        }
        return false;
    }
};