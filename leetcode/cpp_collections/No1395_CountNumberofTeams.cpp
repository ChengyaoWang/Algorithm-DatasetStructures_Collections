# include <vector>
# include <algorithm>
using namespace std;

class Solution {
public:
    int numTeams(vector<int>& rating) {
        int N = rating.size();
        vector<int> sofar = {};
        vector<int> record[4] = {{}, {}, {}, {}};
        for (int i = N - 1; i >= 0; --i) {
            auto loc = upper_bound(sofar.begin(), sofar.end(), rating[i]);
            record[0].push_back(loc - sofar.begin());
            record[1].push_back(sofar.end() - loc);
            sofar.insert(loc, rating[i]);
        }

        sofar.clear();
        for (int i = 0; i < N; ++i) {
            auto loc = upper_bound(sofar.begin(), sofar.end(), rating[i]);
            record[2].push_back(loc - sofar.begin());
            record[3].push_back(sofar.end() - loc);
            sofar.insert(loc, rating[i]);
        }

        reverse(record[0].begin(), record[0].end());
        reverse(record[1].begin(), record[1].end());
        int ret = 0;
        for (int i = 0; i < N; ++i) {
            ret += record[0][i] * record[3][i] + record[1][i] * record[2][i];
        }
        return ret;
    }
};