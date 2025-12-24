# include <vector>
# include <queue>
using namespace std;

class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {

        auto cmp = [&](const int& i, const int& j){
            double i_elem = double(classes[i][0] + 1) / (classes[i][1] + 1);
            double j_elem = double(classes[j][0] + 1) / (classes[j][1] + 1);
            i_elem -= double(classes[i][0]) / classes[i][1];
            j_elem -= double(classes[j][0]) / classes[j][1];
            return j_elem < i_elem;
        };

        priority_queue<int, vector<int>, decltype(cmp)> pq(cmp);
        for (int i = 0; i < classes.size(); ++i)
            pq.push(i);

        for (int i = 0; i < extraStudents; ++i) {
            auto elem = pq.top();
            pq.pop();
            ++classes[elem][0];
            ++classes[elem][1];
            pq.push(elem);
        }

        double ret = 0.;
        while (!pq.empty()) {
            auto elem = pq.top();
            pq.pop();
            ret += double(classes[elem][0]) / classes[elem][1];
        }

        return ret / classes.size();
    }
};