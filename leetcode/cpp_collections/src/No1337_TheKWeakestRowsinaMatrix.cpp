# include <queue>
# include <vector>
# include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        
        auto cmp = [](pair<int, int> i, pair<int, int> j){
            if (i.first == j.first)
                return i.second > j.second;
            return i.first > j.first;
        };

        priority_queue<
            pair<int, int>, vector<pair<int, int>>, decltype(cmp)
        > pq(cmp);

        for (int i = 0; i < mat.size(); ++i) {
            auto cnt = binaryCnt(mat[i]);
            pq.emplace(pair<int, int>{cnt, i});
        }

        vector<int> res = {};
        for (int i = 0; i < k; ++i) {
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;
    }

    int binaryCnt(vector<int> row) {
        int low = 0, up = row.size();
        while (low < up) {
            auto mid = (low + up) / 2;
            if (row[mid] == 1) {
                low = mid + 1;
            } else {
                up = mid;
            }
        }
        return low;
    }
};