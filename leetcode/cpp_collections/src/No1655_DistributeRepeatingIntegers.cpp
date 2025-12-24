# include <vector>
# include <algorithm>
# include <unordered_map>
using namespace std;

class Solution {
public:
    bool canDistribute(vector<int>& nums, vector<int>& quantity) {
        unordered_map<int, int> cnterMap = {};
        for (auto elem: nums)   ++cnterMap[elem];
        vector<int> normedCnter = {};
        for (auto elem: cnterMap)   normedCnter.push_back(elem.second);
        sort(quantity.rbegin(), quantity.rend());
        sort(normedCnter.rbegin(), normedCnter.rend());

        return dfsHelper(0, quantity, normedCnter);
    }

    bool dfsHelper(int i, vector<int>& quantity, vector<int>& normedCnter) {
        if (i == quantity.size())   return true;

        for (auto& elem: normedCnter) {
            if (elem < quantity[i]) continue;
            elem -= quantity[i];
            if (dfsHelper(i + 1, quantity, normedCnter))
                return true;
            elem += quantity[i];
        }

        return false;
    }
};