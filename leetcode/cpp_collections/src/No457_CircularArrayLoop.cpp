# include <vector>
# include <unordered_map>
using namespace std;

class Solution {
public:
    bool circularArrayLoop(vector<int>& nums) {
        int N = nums.size();
        vector<int> seen(N, 0);
        unordered_map<int, int> mem;
        auto move_ptr = [&](int loc, int i) {
            return (loc + i % N + N) % N;
        };

        for (int i = 0; i < N; ++i) {
            if (seen[i] == 1)
                continue;
            int j = i, cnt = 0;
            while (nums[i] < 0 == nums[j] < 0 && !seen[j]) {
                seen[j] = 1;
                mem[j] = ++cnt;
                j = move_ptr(j, nums[j]);
            }
            if (mem.find(j) != mem.end() && mem.at(j) != cnt) {
                return true;
            }
            mem.clear();
        }

        return false;
    }
};