# include <vector>
# include <string>
using namespace std;

class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {

        vector<string> ret;
        vector<int> cnter(26), prevCnter(26);

        for (auto& word: words) {
            
            fill(cnter.begin(), cnter.end(), 0);
            for (auto& c: word)
                ++cnter[c - 'a'];
            
            if (cnter != prevCnter) {
                ret.push_back(word);
                prevCnter = move(cnter);
            }
        }
        return ret;
    }
};