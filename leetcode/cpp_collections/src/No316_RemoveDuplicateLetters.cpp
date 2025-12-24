# include <string>
# include <vector>
using namespace std;


class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> seen(26, 0);
        for (int i = 0; i < s.size(); ++i)
            seen[s[i] - 'a'] = i;

        vector<bool> currentSeen(26, false);
        vector<char> stack = {};
         
        for (int i = 0; i < s.size(); ++i) {

            if (!currentSeen[s[i] - 'a']) {
                while (!stack.empty() && stack.back() > s[i] && seen[stack.back() - 'a'] > i) {
                    auto tmp = stack.back();
                    stack.pop_back();
                    currentSeen[tmp - 'a'] = false;
                }

                stack.push_back(s[i]);
                currentSeen[s[i] - 'a'] = true;
            }
        }

        return string(stack.begin(), stack.end());        
    }
};