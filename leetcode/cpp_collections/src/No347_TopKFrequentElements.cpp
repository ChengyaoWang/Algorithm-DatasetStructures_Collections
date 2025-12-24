# include <vector>
# include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> cnter;
        for (auto &i: nums)
            ++cnter[i];

        vector<pair<int, int>> sortL;
        for (auto &i: cnter)
            sortL.push_back(pair<int, int>(i));
        
        sort(sortL.begin(), sortL.end(), [](auto a, auto b){
            return a.second > b.second;
        });

        vector<int> retL;
        for (int i = 0; i < k; ++i)
            retL.push_back(sortL[i].first);

        return retL;
    }
};