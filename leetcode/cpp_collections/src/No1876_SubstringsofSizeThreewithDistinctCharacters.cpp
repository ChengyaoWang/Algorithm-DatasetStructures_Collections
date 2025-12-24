# include <map>
# include <string>

using namespace std;

class Solution {
public:
    int countGoodSubstrings(string s) {
        
        int ret = 0;
        unordered_map<int, int> cnter;

        for (int i = 0; i < s.size(); ++i) {
            
            cnter[s[i] - 'a']++;
            if (i >= 3 && --cnter[s[i - 3] - 'a'] == 0)
                cnter.erase(s[i - 3] - 'a');
            
            if (cnter.size() == 3)
                ++ret;
        }        

        return ret;
    }
};