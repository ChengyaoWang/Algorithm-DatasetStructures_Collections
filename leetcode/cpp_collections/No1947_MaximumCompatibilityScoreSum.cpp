# include <vector>
# include <functional>
using namespace std;

using mx = vector<vector<int>>;
class Solution {
private:
    int m, n;
    mx scorePre;
public:
    int maxCompatibilitySum(vector<vector<int>>& students, vector<vector<int>>& mentors) {
        
        this -> m = students.size();
        this -> n = students[0].size();
        this -> scorePre = vector<vector<int>> (m, vector<int> (m));
        auto calScore = [&](int a, int b) {
            int matches = 0;
            for (int i = 0; i < n; ++i) {
                matches += (students[a][i] == mentors[b][i]);
            }
            return matches;
        };
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < m; ++j) {
                (this -> scorePre)[i][j] = calScore(i, j);
            }
        }

        return dfs(0, 0, 0, students, mentors);
    }
    
    int dfs(int depth, int mask, int score, mx& students, mx& mentors) {
        
        if (depth == m) {
            return score;
        }

        int ret = -1;
        for (int i = 0; i < m; ++i) {
            if ((mask >> i) & 1)    continue;
            auto tmp = dfs(
                depth + 1, mask | (1 << i),
                score + scorePre[i][depth],
                students, mentors
            );
            ret = max(ret, tmp);
        }
        return ret;
    }

};