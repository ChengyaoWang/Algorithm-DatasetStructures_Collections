# include <vector>
using namespace std;

class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        auto a = edges[0][0], b = edges[0][1];
        auto c = edges[1][0], d = edges[1][1];
        if (a == c || a == d)   return a;
        return b;
    }
};