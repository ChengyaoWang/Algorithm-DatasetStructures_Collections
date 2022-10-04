# include <vector>
# include <string>

using namespace std;

class Solution {
public:
    vector<int> minOperations(string boxes) {

        // Count Number of Balls
        int ball_l = 0, ball_r = 0, moveCnt = 0;
        for (int i = 0; i < boxes.length(); ++i) {
            if(boxes[i] == '1') {
                ball_r += 1;
                moveCnt += i + 1;
            }
        }
        vector<int> res = {};
        for (int i = 0; i < boxes.length(); ++i) {
            moveCnt -= (ball_r - ball_l);
            res.push_back(moveCnt);
            if (boxes[i] == '1') {
                ++ball_l;
                --ball_r;
            }
        }

        return res;
    }
};