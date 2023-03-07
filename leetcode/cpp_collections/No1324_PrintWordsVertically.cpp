# include <vector>
# include <string>
using namespace std;

class Solution {
public:
    vector<string> printVertically(string s) {
        
        int maxLength = -1;
        s.push_back(' ');
        vector<char> buffer = {};
        vector<string> parsed = {};
        for (auto c: s) {
            if (c == ' ') {
                parsed.push_back(string(buffer.begin(), buffer.end()));
                maxLength = max(maxLength, int(buffer.size()));
                buffer.clear();
            } else {
                buffer.push_back(c);
            }
        }

        vector<int> lookahead = {0};
        for (int i = parsed.size() - 1; i > 0; --i) {
            lookahead.push_back(
                max(lookahead.back(), int(parsed[i].size()))
            );
        }
        reverse(lookahead.begin(), lookahead.end());

        vector<string> ret = {};
        for (int i = 0; i < maxLength; ++i) {
            for (int j = 0; j < parsed.size(); ++j) {
                if (parsed[j].size() > i) {
                    buffer.push_back(parsed[j][i]);
                } else if (lookahead[j] > i) {
                    buffer.push_back(' ');
                }
            }
            ret.push_back(string(buffer.begin(), buffer.end()));
            buffer.clear();
        }

        return ret;
    }
};