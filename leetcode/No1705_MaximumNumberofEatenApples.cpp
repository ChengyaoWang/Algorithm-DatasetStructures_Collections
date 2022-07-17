# include <vector>
# include <queue>

using namespace std;

class Solution {
public:
    int eatenApples(vector<int>& apples, vector<int>& days) {

        auto cmp = [](pair<int, int> i, pair<int, int> j) {return i.first > j.first;};

        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> q(cmp);

        int N = apples.size(), cnt = 0;

        for (int d = 0; (d < N) || !q.empty(); ++d) {
            
            if (d < N) {
                q.push(pair<int, int> {d + days[d], apples[d]});
            }

            while (!q.empty() && (q.top().first <= d || q.top().second == 0) ) {
                q.pop();
            }

            if (!q.empty()) {
                auto elem = q.top();
                q.pop();
                q.push(pair<int, int>{elem.first, elem.second - 1});
                ++cnt;
            }
        }
        return cnt;
    }
};