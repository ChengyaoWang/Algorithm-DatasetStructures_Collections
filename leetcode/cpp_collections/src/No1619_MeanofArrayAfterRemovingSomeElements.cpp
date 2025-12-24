# include <queue>
# include <vector>
# include <numeric>
# include <functional>
using namespace std;

class Solution {
public:
    double trimMean(vector<int>& arr) {
        priority_queue<int, vector<int>> maxQ;
        priority_queue<int, vector<int>, greater<int>> minQ;

        double ret = 0.;
        int maxSize = arr.size() / 20;
        for (auto i: arr) {
            maxQ.push(i);
            minQ.push(i);
            if (maxQ.size() > maxSize)   maxQ.pop();
            if (minQ.size() > maxSize)   minQ.pop();
            ret += (double)i;
        }

        while (!maxQ.empty()) {
            ret -= maxQ.top();
            maxQ.pop();
        }
        while (!minQ.empty()) {
            ret -= minQ.top();
            minQ.pop();
        }

        return ret / (arr.size() - 2 * maxSize);
    }
};