# include <vector>
# include <string>
using namespace std;

class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {

        vector<string> ret = {};
        vector<char> buffer = {};
        s.append((k - (s.size() % k)) % k, fill);
        for (auto& c: s) {
            buffer.push_back(c);
            if (buffer.size() == k) {
                ret.push_back(string(buffer.begin(), buffer.end()));
                buffer.clear();
            }
        }

        return ret;
    }
};