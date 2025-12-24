# include <vector>
# include <algorithm>

using namespace std;


class Solution {
private:
    vector<vector<int>> res;
    vector<int> candi;
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        
        sort(candidates.begin(), candidates.end());
        this -> res = vector<vector<int>> {};
        this -> candi = candidates;
        vector<int> sofar = vector<int>{};

        helper(sofar, 0, target);
        return res;
    }


    void helper(vector<int>& sofar, int i, int target) {
        if (target == 0) {
            (this -> res).push_back(sofar);
            return ;
        } else if (target < 0) {
            return ;
        }

        for (int ii = i; ii < (this -> candi).size(); ++ii) {

            if (ii > i && (this -> candi)[ii] == (this -> candi)[ii - 1])
                continue;

            sofar.push_back((this -> candi)[ii]);
            helper(sofar, ii + 1, target - (this -> candi)[ii]);
            sofar.pop_back();
        }
    }
};