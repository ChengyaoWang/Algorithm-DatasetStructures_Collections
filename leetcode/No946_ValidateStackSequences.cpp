# include <vector>

using namespace std;

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {

        vector<int> s;
        int i = 0, ii = 0;
        for (i = 0; i < popped.size();) {
            if (!s.empty() && s.back() == popped[i]) {
                s.pop_back();
                ++i;
            } else {
                if (ii == pushed.size()) {
                    break;
                }
                s.push_back(pushed[ii++]);
            }
        }
        return s.empty() && i == popped.size();
    }
};