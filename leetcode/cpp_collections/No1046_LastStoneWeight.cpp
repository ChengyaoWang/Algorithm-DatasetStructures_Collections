# include <vector>
# include <queue>
using namespace std;

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {

        priority_queue<int, vector<int>> pq;
        for (auto& i: stones) {
            pq.push(i);
        }

        while (pq.size() > 1) {
            auto l = pq.top();
            pq.pop();
            auto r = pq.top();
            pq.pop();
            pq.push(l - r);
        }

        return pq.top();
        
    }
};