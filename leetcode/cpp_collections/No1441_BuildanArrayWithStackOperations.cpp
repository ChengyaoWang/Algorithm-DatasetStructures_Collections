# include <vector>
# include <string>

using namespace std;

class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> res;
        int ptr = 0;
        for (int i = 1; i <= n; ++i) {
            if (target[ptr] != i) {
                res.push_back("Push");
                res.push_back("Pop");
            } else {
                res.push_back("Push");
                ++ptr;
            }
            if (ptr == target.size()) {
                break;
            }
        }
        return res;
    }
};