# include <string>
# include <vector>

using namespace std;

class Solution {
public:
    int countCollisions(string directions) {

        int colli_cnt = 0;
        vector<char> s = {'L'};
        for (auto &i: directions) {
            if (i == 'R') {
                s.push_back('R');
            } else {
                if (i == 'L') {
                    if (s.back() == 'R') {
                        colli_cnt += 2;
                    } else if (s.back() == 'S') {
                        colli_cnt += 1;
                    }
                    s.pop_back();
                }

                while (s.back() == 'R') {
                    colli_cnt += 1;
                    s.pop_back();
                }
                s.push_back('S');
            }
        }

        return colli_cnt;
    }
};