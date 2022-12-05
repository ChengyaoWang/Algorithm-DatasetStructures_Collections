# include <vector>
# include <algorithm>
# include <unordered_map>
using namespace std;

class Solution {
public:
    int longestWPI(vector<int>& hours) {

        transform(
            hours.begin(), hours.end(), hours.begin(),
            [](int a){return a > 8 ? 1: -1;}
        );

        int cumSum = 0, res = 0;
        unordered_map<int, int> seen = {};
        for (int i = 0; i < hours.size(); ++i) {
            cumSum += hours[i];
            if (cumSum > 0) {
                res = i + 1;
            } else {
                if (seen.find(cumSum) == seen.end())
                    seen[cumSum] = i;
                if (seen.find(cumSum - 1) != seen.end())
                    res = max(res, i - seen[cumSum - 1]);

            }
        }

        return res;
    }
};