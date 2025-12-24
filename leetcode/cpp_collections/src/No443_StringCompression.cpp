# include <vector>
# include <string>
using namespace std;

class Solution {
public:
    int compress(vector<char>& chars) {
        chars.push_back('\0');
        int l = chars.size();
        char curC = '\0';
        int slow_p = 0, rep = 0;

        for (int fast_p = 0; fast_p < l; ++fast_p) {
            curC = chars[fast_p];
            rep = 1;
            while ((fast_p < l - 1) && (chars[fast_p + 1] == curC)) {
                ++fast_p;
                ++rep;
            }

            chars[slow_p++] = curC;
            if (rep > 1) {
                for (auto& c: to_string(rep)) {
                    chars[slow_p++] = c;
                }
            }
        }
        
        // chars.resize(slow_p);
        return slow_p;
    }
};