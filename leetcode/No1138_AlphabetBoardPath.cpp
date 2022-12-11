# include <vector>
# include <string>
using namespace std;

class Solution {
public:
    string alphabetBoardPath(string target) {
        vector<pair<int, int>> loc(26);
        for (int i = 0; i < loc.size(); ++i)
            loc[i] = {i / 5, i % 5};

        string res;
        char prevPos = 'a';
        for (auto c: target) {
            cursorMover(
                res,
                loc[c - 'a'].first - loc[prevPos - 'a'].first,
                loc[c - 'a'].second - loc[prevPos - 'a'].second,
                prevPos == 'z'
            );
            prevPos = c;
        };

        return res;
    }

    void cursorMover(string &res, int di, int dj, bool mode) {
        if (mode) {
            res += string(abs(di), (di < 0) ? 'U': 'D');
            res += string(abs(dj), (dj < 0) ? 'L': 'R');
        } else {
            res += string(abs(dj), (dj < 0) ? 'L': 'R');
            res += string(abs(di), (di < 0) ? 'U': 'D');
        }
        res += "!";
    }
};