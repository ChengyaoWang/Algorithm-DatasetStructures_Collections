class Solution {
public:
    int twoEggDrop(int n) {
        int i = 0;
        for (;; ++i) {
            if (i * (i + 1) >= 2 * n) {
                break;
            }
        }
        return i;
    }
};