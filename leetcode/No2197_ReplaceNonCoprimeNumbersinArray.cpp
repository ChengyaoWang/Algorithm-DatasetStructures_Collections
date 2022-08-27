# include <vector>

using namespace std;

class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        vector<int> s = {1};
        int gcd;
        for (auto i: nums) {
            while ((gcd = getGCD(s.back(), i)) != 1) {
                auto tmp = s.back();
                s.pop_back();
                i = i / gcd * tmp;
            }
            s.push_back(i);
        }

        s.erase(s.begin());
        return s;
    }
    
    // We Assume a > b
    int getGCD(int a, int b) {
        if (a < b) swap(a, b);
        if (b == 0 || a == b)   return a;
        return getGCD(a % b, b);
    }

};