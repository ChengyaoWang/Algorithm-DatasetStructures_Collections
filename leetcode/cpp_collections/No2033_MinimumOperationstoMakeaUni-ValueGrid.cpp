# include <vector>
using namespace std;


class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> flatten = {};
        for (auto &vec: grid)
            flatten.insert(flatten.end(), vec.begin(), vec.end());
        
        sort(flatten.begin(), flatten.end());
        int m = grid.size(), n = grid[0].size();
        int mid = flatten[m * n / 2], ret = 0;
        for (auto& c: flatten) {
            if (c % mid != 0)   return -1;
            ret += abs(c - mid) / x;
        }

        return ret;
    }
};