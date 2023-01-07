# include <string>
# include <vector>
# include <numeric>
using namespace std;

class Solution {
public:
    string capitalizeTitle(string title) {
        string ret = "";
        vector<char> tmp = {' '};
        title += " ";
        for (auto c: title) {
            if (c != ' ') {
                tmp.push_back(tolower(c));
                continue;
            }

            if (tmp.size() > 3)
                tmp[1] = toupper(tmp[1]);
            ret += string(tmp.begin(), tmp.end());
            tmp.resize(1);
        }

        return ret.substr(1);
    }
};