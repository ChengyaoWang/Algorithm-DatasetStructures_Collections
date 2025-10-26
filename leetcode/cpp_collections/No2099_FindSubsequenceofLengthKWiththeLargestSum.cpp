# include <stdio.h>
# include <queue>
# include <vector>

using namespace std;

class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<int> retI = {};
        vector<int> ret = {};

        auto cmp_pq = [](pair<int, int> i, pair<int, int> j){
            return i.first > j.first;
        };

        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq(cmp);

        for (int i = 0; i < nums.size(); ++i) {
            pq.push({nums[i], i});
            if (pq.size() > k) {
                pq.pop();
            }
        }
        
        while (!pq.empty()) {
            ret.push_back(pq.top().first);
            retI.push_back(pq.top().second);
            pq.pop();
        }
        sort(
            retI.begin(), retI.end(),
            [&](int i, int j){return retI[i] < retI[j];}
        );

        return ret;        
    }
};