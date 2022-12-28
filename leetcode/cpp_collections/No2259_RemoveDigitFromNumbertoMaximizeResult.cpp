# include <string>
using namespace std;

class Solution {
public:
    string removeDigit(string number, char digit) {
        auto it = findNextOcc(0, number, digit);
        for (;;) {
            auto nextIt = findNextOcc(it + 1, number, digit);
            if (number[it] < number[it + 1] || nextIt == number.size()) {
                number.erase(it + number.begin());
                return number;
            }
            it = nextIt;
        }
    }

    int findNextOcc(int pos, string number, char digit) {
        for (; pos < number.size(); ++pos) {
            if (number[pos] == digit) {
                break;
            }
        }
        return pos;
    }
};