# include <vector>
# include <string>
# include <unordered_set>


using namespace std;

class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        unordered_set<int> set;
        for (int i = 0; i < strs.size() - 1; ++i) {
            for (int j = 0; j < strs[i].length(); ++j) {
                if (set.find(j) != set.end() || strs[i][j] == strs[i+1][j])
                    continue;
                if (strs[i][j] > strs[i+1][j]) {
                    set.insert(j);
                    i = 0;
                }
                break;
            }
        }
        return set.size();
    }
};