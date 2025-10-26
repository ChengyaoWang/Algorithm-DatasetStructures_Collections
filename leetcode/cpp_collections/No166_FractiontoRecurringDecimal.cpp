# include <string>
# include <unordered_map>

using namespace std;

class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        string ret = (numerator < 0) ^ (denominator < 0) ? "-": "";
        if (numerator == 0)     return "0";

        long numLL = numerator;
        long denLL = denominator;

        if (numLL < 0)      numLL *= -1;
        if (denLL < 0)    denLL *= -1;

        unordered_map<int, int> mem;
        ret.append(to_string(numLL / denLL));
        long remainder = numLL % denLL;
        
        if (remainder != 0)
            ret.push_back('.');

        int tmp = 0;
        int i = ret.size();
        mem.insert({remainder, i++});

        while(remainder != 0) {
            remainder *= 10;
            tmp = remainder / denLL;
            remainder %= denLL;

            if (mem.find(remainder) != mem.end()) {
                ret.insert(ret.begin() + mem[remainder], '(');
                ret.push_back(tmp + '0');
                ret.push_back(')');
                return ret;
            }
            mem.insert({remainder, i++});
            ret.push_back(tmp + '0');
        }

        return ret;
    }
};