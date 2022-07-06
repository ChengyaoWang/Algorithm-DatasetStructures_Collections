# include <vector>
# include <string>
# include <unordered_map>

using namespace std;

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {

        if (s.length() < 10) {
            return vector<string>{};
        }

        unordered_map<string, int> map;
        string tmpS;

        for (int i = 0; i < s.length() - 10; ++i) {

            tmpS = s.substr(i, 10);

            if (map.find(tmpS) == map.end()) {
                map.insert({tmpS, 1});
            } else {
                ++map[tmpS];
            }
        }

        vector<string> retList = {};

        for (auto &i: map) {
            if (i.second > 1) {
                retList.push_back(i.first);
            }
        }

        return retList;
    }
};