# include <vector>
# include <string>
# include <unordered_set>
using namespace std;


class Solution {
public:
    long long distinctNames(vector<string>& ideas) {

        vector<unordered_set<string>> cnter(26);
        for (auto elem: ideas) {
            cnter[elem[0] - 'a'].insert(elem.substr(1));
        }

        long long res = 0, r1, r2;
        for (int i = 0; i < 26; ++i) {
            for (int j = 0; j < 26; ++j) {
                r1 = 0; r2 = 0;
                for (auto elem: cnter[i])
                    r1 += int(cnter[j].find(elem) == cnter[j].end());
                for (auto elem: cnter[j])
                    r2 += int(cnter[i].find(elem) == cnter[i].end());
                res += r1 * r2;
            }
        }
        return res;
    }
};