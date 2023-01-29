# include <queue>
# include <vector>
using namespace std;

using p = pair<int, int>;
using pq = priority_queue<p, vector<p>, function<bool (p, p)>>;

class Solution {
public:
    int stoneGameVI(vector<int>& aliceValues, vector<int>& bobValues) {
        pq queue([](p a, p b){
            int A = a.first + a.second, B = b.first + b.second;
            if (A == B)     return a.first < b.first;
            return  A < B;
        });

        int N = aliceValues.size();
        for (int i = 0; i < N; ++i) {
            queue.push({aliceValues[i], bobValues[i]});
        }

        int scoreA = 0, scoreB = 0, rnd = 0;
        while (!queue.empty()) {
            if (rnd & 1) {
                scoreB += queue.top().second;
            } else {
                scoreA += queue.top().first;
            }
            queue.pop();
            ++rnd;
        }
        if (scoreA == scoreB) return 0;
        return scoreA > scoreB ? 1: -1;
    }
};