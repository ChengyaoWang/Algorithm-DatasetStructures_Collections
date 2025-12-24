# include <vector>
# include <queue>
# include <unordered_map>
using namespace std;

using p = pair<int, int>;

class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {

        // Counter
        unordered_map<int, int> cnter = {};
        for (auto& i: barcodes)
            ++cnter[i];

        auto cmp = [&](const p& i, const p& j){
            if (i.second == j.second)
                return i.first < j.first;
            return i.second < j.second;
        };

        priority_queue<p, vector<p>, decltype(cmp)> pq(cmp);
        for (auto& pair: cnter)
            pq.push(pair);
        
        vector<int> ret = {};
        while (!pq.empty()) {
            p elem = pq.top();
            pq.pop();
            if (!ret.empty() && ret.back() == elem.first) {
                p nextElem = pq.top();
                pq.pop();
                ret.push_back(nextElem.first);
                if (--(nextElem.second) > 0) {
                    pq.push(nextElem);
                }
            }
            ret.push_back(elem.first);
            if (--elem.second > 0) {
                pq.push(elem);
            }
        }

        return ret;
    }
};