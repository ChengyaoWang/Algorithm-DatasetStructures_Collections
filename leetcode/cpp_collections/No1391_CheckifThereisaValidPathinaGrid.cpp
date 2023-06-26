# include <vector>
# include <bitset>
using namespace std;

struct Loc {
    int i, j;
    Loc(int a, int b): i(a), j(b) {}
    bool isInv(Loc other) {
        return (
            (i == other.i) && (j != other.j)
        ) || (
            (i != other.i) && (j == other.j)
        );
    }
};

class Solution {
private:
    vector<vector<Loc>> move = {
        {Loc(0, -1), Loc(0, 1)},
        {Loc(-1, 0), Loc(1, 0)},
        {Loc(1, 0), Loc(0, -1)},
        {Loc(0, 1), Loc(1, 0)},
        {Loc(-1, 0), Loc(0, -1)},
        {Loc(0, 1), Loc(-1, 0)},
    };

public:
    bool hasValidPath(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> seen(m, vector<int>(n, 0));

        vector<Loc> s = {};
        s.emplace_back(0, 0);
        
        auto withinRange = [&](int i, int j) {
            return 0 <= i && i < m && 0 <= j && j < n;
        };

        while (!s.empty()) {
            auto elem = s.back();
            s.pop_back();
            seen[elem.i][elem.j] = 1;
            // cout << elem.i << "|" << elem.j << endl;

            if (elem.i == (m - 1) && elem.j == (n - 1))
                return true;

            for (auto& move_i: move[grid[elem.i][elem.j] - 1]) {
                auto di = elem.i + move_i.i;
                auto dj = elem.j + move_i.j;
                if (!withinRange(di, dj) || seen[di][dj])
                    continue;
                auto nextType = grid[di][dj] - 1;
                // cout << di << "|" << dj << endl;
                if (
                    move_i.isInv(move[nextType][0]) ||
                    move_i.isInv(move[nextType][1])
                )
                    s.emplace_back(di, dj);
            }
        }

        return false;
    }
};