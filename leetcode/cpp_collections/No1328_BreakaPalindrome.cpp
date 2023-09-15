# include <string>
using namespace std;

class Solution {
public:
    string breakPalindrome(string palindrome) {
        if (palindrome.size() == 1) {
            return "";
        }

        for (int i = 0; i < palindrome.size(); ++i) {
            if (palindrome[i] != 'a' && (2 * i + 1 != palindrome.size())) {
                palindrome[i] = 'a';
                break;
            } else if (i == palindrome.size() - 1) {
                palindrome[i] = 'b';
                break;
            }
        }

        return palindrome;
    }
};