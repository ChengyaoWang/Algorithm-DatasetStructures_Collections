# include <string>
using namespace std;

class Solution {
public:
    int minOperations(string s) {

        int a = s.back() == '0', b = s.back() == '1';
        for (auto it = next(s.rbegin()); it != s.rend(); ++it) {
            a += (*it) == '0';
            b += (*it) == '1';
            swap(a, b);
        }

        return min(a, b);
    }
};