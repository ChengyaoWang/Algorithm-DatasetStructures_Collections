# include <vector>
using namespace std;

class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        bool a = true, b = true, c = true, d = true;
        int n = mat.size();

        auto update = [&](int i, int j) {
            int x = n - 1 - i, y = n - 1 - j;
            a &= (mat[i][j] == target[i][j]);
            b &= (mat[i][j] == target[j][x]);
            c &= (mat[i][j] == target[x][y]);
            d &= (mat[i][j] == target[y][i]);
        };
        
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                update(i, j);
        
        return a || b || c || d;
    }
};