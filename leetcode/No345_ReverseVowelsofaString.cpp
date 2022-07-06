# include <string>
# include <unordered_set>

using namespace std;

class Solution {
public:
    unordered_set<char> vowel = {
        'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'
    };
    string reverseVowels(string s) {
        int lp = 0, rp = s.length() - 1;
        while (lp < rp) {
            if (vowel.find(s[lp]) == vowel.end()) {
                ++lp;
            } else if (vowel.find(s[rp]) == vowel.end()) {
                --rp;
            } else {
                swap(s[lp++], s[rp--]);
            }
        }
        return s;
    }
};