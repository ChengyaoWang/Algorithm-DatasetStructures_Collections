# include <string>
# include <vector>

using namespace std;

class Solution {
public:
    string maximumNumber(string num, vector<int>& change) {
        
        for (auto &i: num) {
            if (i - '0' >= change[i - '0'])
                continue;

            while (i - '0' < change[i - '0']) {
                i = change[i - '0'] + '0';
            }
            return num;
        }
    }
};