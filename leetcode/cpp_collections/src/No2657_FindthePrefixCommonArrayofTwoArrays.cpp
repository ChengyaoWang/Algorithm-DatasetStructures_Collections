# include <vector>
# include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {

        auto n = A.size();
        unordered_map<int, int> mem;

        vector<int> ret = {};
        for (int i = 0; i < n; ++i) {
            auto tmp = ret.empty() ? 0: ret.back();
            if (++mem[A[i]] == 2)
                ++tmp;
            if (++mem[B[i]] == 2)
                ++tmp;
            ret.push_back(tmp);
        }

        return ret;
    }
};