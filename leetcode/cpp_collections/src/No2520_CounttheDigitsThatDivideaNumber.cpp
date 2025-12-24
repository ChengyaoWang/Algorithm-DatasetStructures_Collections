class Solution {
public:
    int countDigits(int num) {
        int cnt = 0, num_cpy = num;
        while (num) {
            auto re = num % 10;
            cnt += (num_cpy % re == 0);
            num /= 10;
        }

        return cnt;
    }
};