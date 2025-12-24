# include <vector>
# include <string>
using namespace std;

class Solution {
public:
    string robotWithString(string s) {
        vector<char> buffer = {};
        vector<int> cnter(26, 0);
        for (auto& c: s)
            ++cnter[c - 'a'];

        char tgt_c = 'a';
        string ret = "";
        for (auto c: s) {

            buffer.push_back(c);
            --cnter[c - 'a'];
            
            while (tgt_c <= 'z' && cnter[tgt_c - 'a'] == 0) {
                ++tgt_c;
            }
            while (!buffer.empty() && buffer.back() <= tgt_c) {
                auto tmp = buffer.back();
                buffer.pop_back();
                ret.push_back(tmp);
            }
        }

        return ret + string(buffer.rbegin(), buffer.rend());
    }
};