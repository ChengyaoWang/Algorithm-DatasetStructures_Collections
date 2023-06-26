# include <string>
using namespace std;

class Solution {
public:
    int minTimeToType(string word) {

        char loc = 'a';
        int ret = 0;
        
        for (auto& c: word) {
            ret += min((c - loc + 26) % 26, (loc - c + 26) % 26);
            loc = c;
        }
        return ret + word.size();
    }
};