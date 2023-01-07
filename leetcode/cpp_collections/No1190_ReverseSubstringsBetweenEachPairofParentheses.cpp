# include <string>
# include <vector>
using namespace std;

class Solution {
public:
    string reverseParentheses(string s) {

        vector<vector<char>> vec_s = {{}};
        for (auto& c: s) {
            if (c == '(') {
                vec_s.push_back({});
            } else if (c == ')') {
                auto last_s = vec_s.back();
                vec_s.pop_back();
                vec_s.back().insert(vec_s.back().end(), last_s.rbegin(), last_s.rend());
            } else {
                vec_s.back().push_back(c);
            }
        }

        return string(vec_s[0].begin(), vec_s[0].end());
    }
};