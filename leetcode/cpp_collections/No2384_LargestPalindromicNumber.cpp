# include <string>
# include <vector>
using namespace std;

class Solution {
public:
    string largestPalindromic(string num) {
        vector<int> cnter(10);
        for (auto& c: num)
            ++cnter[c - '0'];

        int maxRemainNum = -1;
        string firstHalf;
        for (int i = 9; i >= 0; --i) {
            while (cnter[i] > 1) {
                firstHalf.push_back(i + '0');
                cnter[i] -= 2;
            }
            if (cnter[i] == 1)
                maxRemainNum = max(maxRemainNum, i);
        }

        if (firstHalf.front() == '0' || firstHalf.empty()) {
            return (maxRemainNum == -1) ? "0": to_string(maxRemainNum);
        }

        string secondHalf = firstHalf;
        reverse(secondHalf.begin(), secondHalf.end());
        if (maxRemainNum != -1)
            firstHalf.push_back(maxRemainNum + '0');
        return firstHalf + secondHalf;
    }
};