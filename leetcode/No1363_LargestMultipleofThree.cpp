# include <vector>
# include <string>
# include <algorithm>
# include <numeric>
# include <functional>
# include <unordered_map>

using namespace std;

class Solution {
public:
    string largestMultipleOfThree(vector<int>& digits) {

        unordered_map<int, int> cnter = {};
        int sumRes3 = 0;
        for (auto i: digits) {
            ++cnter[i];
            sumRes3 = (sumRes3 + i) % 3;
        }

        if (sumRes3 == 1) {
            if ((cnter[1] + cnter[4] + cnter[7]) > 0) {
                dec(cnter, vector<int> {1, 4, 7}, 1);
            } else {
                dec(cnter, vector<int> {2, 5, 8}, 2);
            }
        } else if (sumRes3 == 2) {
            if ((cnter[2] + cnter[5] + cnter[8]) > 0) {
                dec(cnter, vector<int> {2, 5, 8}, 1);
            } else {
                dec(cnter, vector<int> {1, 4, 7}, 2);
            }
        }

        string res = map2str(cnter);
        return (res[0] == '0') ? "0": res;

    }
    string map2str (unordered_map<int, int> cnter) {
        string starter = "";
        for (int i = 9; i >= 0; --i) {
            starter += string(cnter[i], '0' + i);
        }
        return starter;
    }
    void dec(unordered_map<int, int>& map, vector<int> vec, int dec_amt) {
        int temp = 0;
        for (int i = 0; i < vec.size(); ++i) {
            temp = min(map[vec[i]], dec_amt);
            map[vec[i]] -= temp;
            dec_amt -= temp;
        }
    }
};