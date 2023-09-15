# include <vector>
# include <unordered_map>
using namespace std;

class Solution {
public:
    void insert(int i, vector<int>& list, vector<int>& scores) {
        list.push_back(i);
        int n = list.size() - 1;
        while (n > 0 && scores[list[n]] > scores[list[n - 1]]) {
            swap(list[n], list[n - 1]);
            --n;
        }
        if (list.size() > 3)
            list.pop_back();
    }
    
    int getMax(
        const int& i, const int& j,
        const vector<int>& il, const vector<int>& jl,
        const vector<int>& scores
    ) {
        int ii = 0, jj = 0;
        if (il[ii] == j) {
            if (il.size() == ++ii)
                return -1;
        }

        if (jl[jj] == i || jl[jj] == il[ii]) {
            if (jl.size() == ++jj)
                return -1;
        }
        if (jl[jj] == i || jl[jj] == il[ii]) {
            if (jl.size() == ++jj)
                return -1;
        }        

        return scores[il[ii]] + scores[jl[jj]];
    }

    int maximumScore(vector<int>& scores, vector<vector<int>>& edges) {

        unordered_map<int, vector<int>> mem;

        for (auto& e: edges) {
            insert(e[1], mem[e[0]], scores);
            insert(e[0], mem[e[1]], scores);
        }

        // Try and get Result
        int ret = -1;
        for (auto& e: edges) {
            auto l = e[0], r = e[1];
            auto retTmp = max(
                getMax(l, r, mem[l], mem[r], scores),
                getMax(r, l, mem[r], mem[l], scores)
            );
            if (retTmp == -1)
                continue;
            ret = max(ret, scores[l] + scores[r] + retTmp);
        }

        return ret;        
    }
};