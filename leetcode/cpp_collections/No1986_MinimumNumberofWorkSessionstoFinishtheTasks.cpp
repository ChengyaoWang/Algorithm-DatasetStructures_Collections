# include <vector>
# include <string>
# include <unordered_map>
using namespace std;

class Solution {
public:
    int minSessions(vector<int>& tasks, int sessionTime) {
        vector<int> sessionList;
        unordered_map<string, int> dp;
        sort(tasks.begin(), tasks.end());
        return dfs(0, sessionTime, tasks, sessionList, dp);
    }

    int dfs(
        int depth,
        int sessionTime,
        vector<int>& tasks,
        vector<int>& sessionList,
        unordered_map<string, int>& dp
    ) {
        if (depth == tasks.size()) {
            return 0;
        }
        string s = "";
        auto cpy = vector<int> {};
        copy(sessionList.begin(), sessionList.end(), cpy.begin());
        for (auto& i: cpy) {
            s += to_string(i) + " ";
        }

        if (dp.find(s) != dp.end()) {
            return dp[s];
        }

        sessionList.push_back(tasks[depth]);
        auto ret = 1 + dfs(depth + 1, sessionTime, tasks, sessionList, dp);
        sessionList.pop_back();

        for (int i = 0; i < sessionList.size(); ++i) { 
            auto elem = sessionList[i];
            if (elem + tasks[depth] <= sessionTime) {
                sessionList[i] += tasks[depth];
                ret = min(ret, dfs(depth + 1, sessionTime, tasks, sessionList, dp));
                sessionList[i] -= tasks[depth];
            }
        }
        dp[s] = ret;
        return ret;
    }
};