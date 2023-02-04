# include <string>
using namespace std;

class Solution {
public:
    bool checkIfPangram(string sentence) {
        int cnt = 0;
        for (auto& c: sentence)
            cnt |= (1 << (c - 'a'));
        return cnt == ((1 << 26) - 1);
    }
};