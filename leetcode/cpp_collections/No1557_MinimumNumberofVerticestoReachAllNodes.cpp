# include <vector>
# include <unordered_set>
using namespace std;

class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        
        unordered_set<int> mem = {};
        for (auto& e: edges) {
            mem.insert(e[1]);
        }
        vector<int> ret;
        for (int i = 1; i <= n; ++i) {
            if (mem.find(i) != mem.end())
                continue;
            ret.push_back(i);
        }
        
        return ret;
    }
};