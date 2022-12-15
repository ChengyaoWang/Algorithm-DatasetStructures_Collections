# include <string>
# include <queue>
using namespace std;

class Solution {
public:
    string reformat(string s) {
        queue<char> *qd = new queue<char>(), *qc = new queue<char>();
        for (char c: s) {
            if (isdigit(c)) {
                qd -> push(c);
            } else {
                qc -> push(c);
            }
        }

        if (qd -> size() < qc -> size())
            swap(qd, qc);
        if (qd -> size() > qc -> size() + 1)
            return "";

        string res = "";
        while (!qd -> empty() || !qc -> empty()) {
            auto tmp = qd -> front();
            qd -> pop();
            res.push_back(tmp);
            swap(qd, qc);
        }
        return res;
    }
};