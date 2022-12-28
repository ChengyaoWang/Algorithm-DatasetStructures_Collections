# include <vector>

using namespace std;

class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int N = code.size();
        vector<int> res(N, 0);
        if (k == 0) {
            return res;
        }

        for (int i = 0; i < N; ++i) {
            int j = k;
            while (j != 0) {
                res[i] += code[i + j];
                j += (k < 0) ? 1: -1;
            }
        }

        return res;
    }
};