
class Solution {
public:
    int minimumBoxes(int n) {
        
        int order = 1;
        for(;;++order) {
            auto tmp = order * (order + 1) / 2;
            if (n < tmp)    break;
            n -= tmp;
        }
        
        int order_sec = 0;
        while (n > 0) {
            n -= ++order_sec;
        }

        return (order - 1) * order / 2 + order_sec;
    }
};