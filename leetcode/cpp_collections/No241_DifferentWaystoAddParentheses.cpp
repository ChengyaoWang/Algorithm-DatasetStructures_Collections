# include <vector>
# include <string>
# include <unordered_set>
using namespace std;

class Solution {
public:

    int cal(char op, int a, int b) {
        if (op == '+') {
            return a + b;
        } else if (op == '-') {
            return a - b;
        }
        return a * b;
    }

    bool is_number(const string& s) {
        return !s.empty() && find_if(
            s.begin(), s.end(),
            [](unsigned char c) { return !isdigit(c); }
        ) == s.end();
    }

    vector<int> diffWaysToCompute(string expression) {
        
        if (is_number(expression)) {
            return vector<int>{stoi(expression)};
        }

        vector<int> ret = {};
        for (int i = 0; i < expression.size(); ++i) {
            auto c = expression[i];
            if (c == '+' || c == '-' || c == '*') {
                auto res1 = diffWaysToCompute(expression.substr(0, i));
                auto res2 = diffWaysToCompute(expression.substr(i + 1));
                
                for (auto& p: res1) {
                    for (auto& q: res2) {
                        ret.push_back(cal(c, p, q));
                    }
                }
            }
        }

        return ret;
    }
};