# include <string>
using namespace std;

using ll = long long;
class Solution {
private:
    ll gcd(ll a, ll b) {
        if (b == 0) return a;
        if (a < b)  swap(a, b);
        return      gcd(b, a % b);
    }
public:
    string fractionAddition(string expression) {
        bool insertNumer = false;
        ll flag = 1;
        pair<ll, ll> cum = {0, 1}, buf = {0, 1};
        expression.push_back('+');
        if (expression[0] != '-')
            expression.insert(expression.begin(), '+');
        for (auto& c: expression) {
            if (isdigit(c)) {
                ll& t = insertNumer ? buf.first: buf.second;
                t = 10 * t + (c - '0');
                continue;
            }
            if (c == '+' || c == '-') {
                cum.first = cum.first * buf.second + flag * cum.second * buf.first;
                cum.second = cum.second * buf.second;
                auto elem = gcd(abs(cum.second), abs(cum.first));
                cum.first /= elem;
                cum.second /= elem;
                buf = {0, 0};
                flag = c == '+' ? 1: -1;
            }
            insertNumer = !insertNumer;
        }

        return to_string(cum.first) + "/" + to_string(cum.second);
    }
};