# include <vector>
# include <string>
# include <numeric>
# include <algorithm>
# include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {
        unordered_map<string, int> revMapper = {};
        for (int i = 0; i < req_skills.size(); ++i) {
            revMapper[req_skills[i]] = i;
        }

        unordered_map<int, vector<int>> dp = {{0, {}}};
        for (int i = 0; i < people.size(); ++i) {
            auto enc_person = accumulate(
                people[i].begin(), people[i].end(), 0, [&](int &res, string b) {
                    return res | (1 << revMapper[b]);
                }
            );
            
            vector<int> curSet;
            for (auto p: dp)    curSet.push_back(p.first);
            for (auto p: curSet) {
                int dest = p | enc_person;
                if (dest == p)  continue;
                if (dp.find(dest) == dp.end() || dp[p].size() < (dp[dest].size() - 1)) {
                    dp[dest] = dp[p];
                    dp[dest].push_back(i);
                }
            }
        }
        
        return dp[(1 << req_skills.size()) - 1];
    }
};