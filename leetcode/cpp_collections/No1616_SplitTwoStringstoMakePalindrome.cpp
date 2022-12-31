# include <string>
using namespace std;

class Solution {
public:
    bool checkPalindromeFormation(string a, string b) {
        int i = max(findSplitPoint(a, b), findSplitPoint(b, a));
        auto isPalindrome = [](string s, int l){
            int r = s.size() - 1 - l;
            while (l < r) {
                if (s[l] != s[r])   return false;
                ++l; --r;
            }
            return true;
        };
        return isPalindrome(a, i) || isPalindrome(b, i);
    }

    int findSplitPoint(string a, string b) {
        int i = 0, n = a.size() - 1;
        while (i < n - i && a[i] == b[n - i]) {
            ++i;
        }
        return i;
    }
};