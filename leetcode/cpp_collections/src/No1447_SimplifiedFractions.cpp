# include <vector>
# include <string>
using namespace std;

class Solution {
public:
    string compose(int numer, int demon) {
        return to_string(numer) + "/" + to_string(demon);
    }
    int gcd(int a, int b) {
        if (b == 0) {
            return a;
        }
        return gcd(b, a % b);
    }

    vector<string> simplifiedFractions(int n) {
        
        vector<string> ret;
        for (int demon = 1; demon <= n; ++demon) {

            int numer = 1;
            while (numer < demon) {
                if (gcd(numer, demon) == 1) {
                    auto s = compose(numer, demon);
                    ret.push_back(s);
                }
                ++numer;
            }
        }

        return ret;
    }
};