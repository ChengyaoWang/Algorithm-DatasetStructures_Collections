# include <vector>
# include <string>

using namespace std;

class Solution {
public:
    int minOperations(vector<string>& logs) {
        int depth = 0;
        for (auto &i: logs) {
            if (i == "../") --depth;
            else if (i == "./") {}
            else ++depth;
            depth = max(depth, 0);
        }
        return depth;
    }
};