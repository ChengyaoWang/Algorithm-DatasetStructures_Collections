# include <vector>
# include <string>
using namespace std;

using ll = long long;

class Solution {
public:
    ll target;
    string num;

    void dfs(
        int depth, ll add, ll mul, ll last,
        string pth, vector<string>& ret
    ) {
        if (depth == num.size()) {
            if ((add + mul * last) == target) {
                ret.push_back(pth);
            }
            return;
        }
        int curNum = num[depth] - '0';
        dfs(depth + 1, add, mul * last, curNum, pth + '*' + num[depth], ret);
        dfs(depth + 1, add + mul * last, 1, curNum, pth + '+' + num[depth], ret);
        dfs(depth + 1, add + mul * last, 1, -curNum, pth + '-' + num[depth], ret);
        if (last != 0)
            dfs(depth + 1, add, mul, (last > 0 ? last * 10 + curNum: last * 10 - curNum), pth + num[depth], ret);
        return ;
    }

    vector<string> addOperators(string num, int target) {

        this -> target = ll(target);
        this -> num = num;

        vector<string> ret;
        ll initLL = ll(num[0] - '0');
        string pth = string{num[0]};
        dfs(1, 0LL, 1LL, initLL, pth, ret);
        return ret;
    }
};