# include <string>
# include <vector>
# include <algorithm>
using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {

        string ret = "";
        int m = num1.size(), n = num2.size();
        vector<vector<int>> mul(m, vector<int> (n, 0));

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                mul[i][j] = (num1[i] - '0') * (num2[j] - '0');
            }
        }

        int carry = 0;
        for (int i = (m + n - 2); i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                auto k = i - j;
                if (k < 0 || k >= m)
                    continue;
                carry += mul[k][j];
            }
            ret.push_back(carry % 10 + '0');
            carry /= 10;
        }

        reverse(ret.begin(), ret.end());
        ret = to_string(carry) + ret;
        auto st = ret.find_first_not_of('0');
        return (st == string::npos) ? "0": ret.substr(st, string::npos);
    }
};