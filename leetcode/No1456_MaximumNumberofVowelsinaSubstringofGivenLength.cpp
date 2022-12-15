# include <string>
# include <unordered_set>
using namespace std;


class Solution {
public:
    int maxVowels(string s, int k) {
        unordered_set<char> vowelSet = {'a', 'e', 'i', 'o', 'u'};
        auto isVowel = [&](char c) {return int(vowelSet.find(c) != vowelSet.end());};

        int cnt = 0, res = 0;
        for (int i = 0; i < s.size(); ++i) {
            cnt += isVowel(s[i]);
            if (i >= k)     cnt -= isVowel(s[i - k]);
            res = max(res, cnt);
        }

        return res;
    }
};