# include <vector>
# include <limits>

using namespace std;

class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {

        vector<vector<int>> dp(numCourses, vector<int> (numCourses, numCourses * numCourses));

        for (auto& p: prerequisites)
            dp[p[0]][p[1]] = 1;
        
        for (int i = 0; i < numCourses; ++i)
            dp[i][i] = 0;

        for (int i = 0; i < numCourses; ++i) {
            for (int j = 0; j < numCourses; ++j) {
                for (int k = 0; k < numCourses; ++k) {
                    if (i != j && i != k && j != k) {
                        if (dp[j][k] > dp[j][i] + dp[i][k]) 
                            dp[j][k] = dp[j][i] + dp[i][k];
                    }
                }
            }
        }

        vector<bool> retList;
        for (auto& q: queries) {
            retList.push_back(dp[q[0]][q[1]] != numCourses * numCourses);
        }

        return retList;
    }
};