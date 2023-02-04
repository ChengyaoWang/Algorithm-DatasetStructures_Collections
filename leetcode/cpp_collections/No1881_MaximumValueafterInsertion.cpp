# include <string>
using namespace std;

class Solution {
public:
    string maxValue(string n, int x) {
        
        int i = 0;
        bool isNeg = n[i] == '-';
        if (isNeg)  ++i;
        
        for (; i < n.size(); ++i) {
            if ((n[i] - '0') == x)  continue;
            auto tmp = (n[i] - '0') < x;
            if (tmp ^ isNeg)    break;
        }

        n.insert(i, to_string(x));
        return n;
    }
};