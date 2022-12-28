# include <vector>
# include <string>
# include <regex>

using namespace std;

class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int> call_stack;
        vector<int> retList(n, 0);
        string log;
        int prev_t = 0;
        
        for (auto log: logs) {
            auto f = stoi(log.substr(0, log.find(':')));
            auto t = stoi(log.substr(log.rfind(':') + 1, log.length() - log.rfind(':')));
            auto status = log[log.find(':') + 1] == 's';

            if (call_stack.empty()) {
                call_stack.push_back(f);
                prev_t = t;
            } else if (status) {
                retList[call_stack.back()] += (t - prev_t);
                call_stack.push_back(f);
                prev_t = t;
            } else {
                retList[call_stack.back()] += (t - prev_t + 1);
                call_stack.pop_back();
                prev_t = t + 1;
            }
        }
        return retList;
    }
};