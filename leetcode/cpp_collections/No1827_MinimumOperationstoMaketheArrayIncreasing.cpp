class Solution {
public:
    int minOperations(vector<int>& nums) {
        int ops = 0, tmp = -1;

        for (auto& it: nums) {
            tmp = max(tmp + 1, it);
            ops += (tmp - it)
        }

        return ops;
    }

    int max(int i, int j) {
        return (i >= j) ? i: j
    }

};