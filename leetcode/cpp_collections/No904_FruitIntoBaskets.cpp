# include <queue>
# include <vector>
using namespace std;

class Solution {
public:
    int totalFruit(vector<int>& fruits) {

        int ret = 0, tmp = 0;
        pair<int, queue<int>> p1 = {-1, {}}, p2 = {-1, {}};

        for (int i = 0; i < fruits.size(); ++i) {
            auto elem = fruits[i];
            if (p1.first == elem) {
                p1.second.push(i);
            } else if (p2.first == elem || p2.first == -1) {
                p2.first = elem;
                p2.second.push(i);
            } else {
                while (!p1.second.empty() && !p2.second.empty()) {
                    if (p1.second.front() < p2.second.front()) {
                        p1.second.pop();
                    } else {
                        p2.second.pop();
                    }
                    --tmp;
                }
                if (p1.second.empty()) {
                    p1.first = elem;
                    p1.second.push(i);
                } else {
                    p2.first = elem;
                    p2.second.push(i);
                }
            }
            ret = max(ret, ++tmp);
        }
        return ret;
    }
};