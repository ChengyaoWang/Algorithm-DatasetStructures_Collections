# include <cmath>

class Solution {
public:
    int pivotInteger(int n) {
        auto root = sqrt(double(n * n + n) / 2);
        if (root == int(root)) {
            return int(root);
        }
        return -1;
    }
};