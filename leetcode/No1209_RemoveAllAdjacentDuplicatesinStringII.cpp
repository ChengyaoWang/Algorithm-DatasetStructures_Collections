# include <string>
# include <vector>

using namespace std;

class Solution {
public:
    string removeDuplicates(string s, int k) {
        vector<pair<char, int>> vec;
        
        for (auto &i: s) {
            if (!vec.empty() && vec.back().first == i) {
                ++vec.back().second;
            } else {
                vec.push_back({i, 1});
            }

            vec.back().second %= k;
            if (vec.back().second == 0) {
                vec.pop_back();
            }
        }

        string res;
        for (auto &i: vec) {
            for (int dup = 0; dup < i.second; ++dup) {
                res.push_back(i.first);
            }
        }

        return res;
    }
};