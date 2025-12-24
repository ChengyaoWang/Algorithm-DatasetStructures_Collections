# include <vector>
# include <string>
using namespace std;

class Solution {
public:
    vector<long long> kthPalindrome(vector<int>& queries, int intLength) {
        
        int mid = (intLength - 1) / 2, l = (intLength + 1) / 2;
        vector<long long> ret = {};
        for (auto num: queries) {
            string ori(intLength, '0');
            ori[0] = '1';
            ori[intLength - 1] = '1';
            --num;
            for (int iter = mid; iter >= 0 && num > 0; --iter) {
                int div = (iter == 0 ? 9: 10);
                ori[iter] += num % div;
                if (iter != mid || (intLength % 2 == 0))
                    ori[intLength - 1 - iter] += num % div;
                num /= div;
            }
            if (num != 0) {
                ret.push_back(-1);
            } else {
                ret.push_back(stoll(ori));
            }
        }
        return ret;
    }
};