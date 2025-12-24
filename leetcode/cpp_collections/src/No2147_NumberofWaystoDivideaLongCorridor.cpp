# include <string>
using namespace std;

class Solution {
public:
    int numberOfWays(string corridor) {
        
        long long ret = 1;
        int totalSeats = 0;
        int seatCnt = 0, plantCnt = 0;

        for (auto& c: corridor) {
            if (c == 'P') {
                plantCnt += (seatCnt == 2);
            } else {
                ++totalSeats;
                if (++seatCnt == 3) {
                    ret *= (plantCnt + 1);
                    ret %= 1000000007;
                    seatCnt %= 2;
                    plantCnt = 0;
                }
            }
        }

        return (totalSeats == 0) || (totalSeats % 2 == 1) ? 0: int(ret);
    }
};