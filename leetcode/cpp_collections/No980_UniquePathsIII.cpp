# include <vector>
using namespace std;

class Solution {
private:
    int m, n, totalSteps;
    vector<pair<int, int>> moves = {
        {-1, 0}, {1, 0}, {0, -1}, {0, 1}
    };
    
    bool withinRange(int i, int j) {
        return i >= 0 && i < m && j >= 0 && j < n;
    }

public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        this -> m = grid.size();
        this -> n = grid[0].size();
        
        this -> totalSteps = 1;
        int sr, sc;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    sr = i; sc = j;
                } else if (grid[i][j] == 0) {
                    ++this -> totalSteps;
                }
            }
        }

        return dfsHelper(sr, sc, 0, grid);
    }

    int dfsHelper(int i, int j, int curStep, vector<vector<int>>& grid) {

        if (!withinRange(i, j) || grid[i][j] < 0) {
            return 0;
        } else if (grid[i][j] == 2) {
            return (curStep == totalSteps);
        }

        grid[i][j] = -1;
        int cnt = 0;
        for (auto m: moves) {
            cnt += dfsHelper(i + m.first, j + m.second, curStep + 1, grid);
        }
        grid[i][j] = 0;
        return cnt;
    }

};