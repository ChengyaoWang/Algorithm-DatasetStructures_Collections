# include <vector>
using namespace std;

class Solution {
public:
    int hardestWorker(int n, vector<vector<int>>& logs) {
        int prevEnd = 0, t, ret = -1, maxT = -1;
        for (auto& elem: logs) {
            t = elem[1] - prevEnd;
            if (t > maxT) {
                ret = elem[0];
                maxT = t;
            } else if (t == maxT && elem[0] < ret) {
                ret = elem[0];
            }
            prevEnd = elem[1];
        }

        return ret;
    }
};