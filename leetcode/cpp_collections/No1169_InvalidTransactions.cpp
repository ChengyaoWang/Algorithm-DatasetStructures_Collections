# include <vector>
# include <string>
# include <numeric>
# include <algorithm>
# include <unordered_map>
using namespace std;


class Info {
public:
    string init, name, loc;
    int t, amt;
    Info(string init) {
        int i = init.find(',', 0);
        this -> name = init.substr(0, i);
        int j = init.find(',', i + 1);
        this -> t = stoi(init.substr(i + 1, j - i - 1));
        int k = init.find(',', j + 1);
        this -> amt = stoi(init.substr(j + 1, k - j - 1));
        this -> loc = init.substr(k + 1, init.size() - k - 1);
        this -> init = init;
    }
};

class Solution {
public:
    vector<string> invalidTransactions(vector<string>& transactions) {

        unordered_map<string, vector<Info>> vec = {};
        for (auto& s: transactions) {
            auto tmp = Info(s);
            vec[tmp.name].push_back(tmp);
        }

        vector<string> ret = {};
        for (auto& p: vec) {
            for (auto& elem: p.second) {
                if (elem.amt >= 1000) {
                    ret.push_back(elem.init);
                    continue;
                }
                for (auto& elem1: p.second) {
                    if (elem.loc != elem1.loc && abs(elem.t - elem1.t) <= 60) {
                        ret.push_back(elem.init);
                        break;
                    }
                }
            }
        }
        return ret;
    }
};