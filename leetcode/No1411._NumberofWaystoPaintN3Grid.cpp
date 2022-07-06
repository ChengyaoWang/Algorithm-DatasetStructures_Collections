class Solution {
public:
    /*
        101 -> 010, 020, 212 / 012, 210
        012 -> 101, 121 / 201, 120
    */



    int numOfWays(int n) {
        int a = 6, b = 6;
        int tmp_a, tmp_b;

        for (int i = 1; i < n; i++) {
            tmp_a = (3 * a + 2 * b) % (10e9 + 7);
            

        }



    }
};