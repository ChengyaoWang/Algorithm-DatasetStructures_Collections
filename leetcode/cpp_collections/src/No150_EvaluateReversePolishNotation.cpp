# include <vector>
# include <string>
# include <unordered_set>

using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        
        vector<int> stack;
        unordered_set<string> set = {"+", "-", "*", "/"};

        for (auto &i: tokens) {
            if (set.find(i) != set.end()) {
                auto b = stack.back();
                stack.pop_back();
                auto a = stack.back();
                stack.pop_back();
                if (i == "+") {
                    stack.push_back(a + b);
                } else if (i == "-") {
                    stack.push_back(a - b);
                } else if (i == "*") {
                    stack.push_back(a * b); 
                } else {
                    stack.push_back(a / b);
                }
            } else {
                stack.push_back(stoi(i));
            }
        }
        return stack.back();

    }
};