# include <vector>
# include <queue>
using namespace std;

class Solution {
private:
    int moves[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m = image.size(), n = image[0].size();
        int colorToFind = image[sr][sc];
        deque<pair<int, int>> q = {};
        auto withinRange = [=](int i, int j) {
            return i >= 0 && i < m && j >= 0 && j < n;
        };
        
        q.push_back({sr, sc});
        while (!q.empty()) {
            auto tmp = q.front();
            q.pop_front();
            if (image[tmp.first][tmp.second] == color)
                continue;
            image[tmp.first][tmp.second] = color;
            for (auto i: moves) {
                int di = tmp.first + i[0], dj = tmp.second + i[1];
                if (withinRange(di, dj) && (image[di][dj] == colorToFind))
                    q.push_back({di, dj});
            }
        }
        
        return image;
    }
};