# include <vector>
# include <string>
# include <algorithm>
using namespace std;

class Solution {
public:
    bool digitCount(string num) {
        vector<int> cnter(10);
        for (int i = 0; i < num.size(); ++i) {
            cnter[i] += num[i] - '0';
            --cnter[num[i] - '0'];
        }

        return all_of(cnter.begin(), cnter.end(), [](int elem){
            return elem == 0;
        });
    }
};