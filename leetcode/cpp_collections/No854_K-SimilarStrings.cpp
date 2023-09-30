# include <string>
# include <vector>
# include <numeric>
# include <unordered_map>
using namespace std;

class Solution {
public:
    int dfs(string& s1, string& s2, int i) {
        int n = s1.size();
        if (i == n) {
            return 0;
        } else if (s1[i] == s2[i]) {
            return dfs(s1, s2, i + 1);
        }

        vector<int> goodswap = {};
        for (int j = i + 1; j < n; ++j) {
            if (s1[j] == s2[i] && s1[j] != s2[j]) {
                goodswap.push_back(j);
                if (s1[i] == s2[j]) {
                    swap(s1[i], s1[j]);
                    return 1 + dfs(s1, s2, i + 1);
                }
            }
        }

        int opt = s1.size() - i;
        for (auto& j: goodswap) {
            swap(s1[i], s1[j]);
            opt = min(opt, 1 + dfs(s1, s2, i + 1));
            swap(s1[i], s1[j]);
        }
        return opt;
    }

    int kSimilarity(string s1, string s2) {
        return dfs(s1, s2, 0);
    }
};