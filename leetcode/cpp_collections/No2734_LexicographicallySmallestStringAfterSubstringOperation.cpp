# include <string>
# include <vector>
using namespace std;

class Solution {
public:
    string smallestString(string s) {

        vector<char> vec(s.begin(), s.end());
        vector<char>::iterator it = vec.begin();

        while (it != vec.end() && (*it) == 'a') {
            ++it;
        }

        if (it == vec.end()) {
            *(it - 1) = 'z';
        } else {
            while (it != vec.end() && (*it) != 'a') {
                --(*it++);
            }
        }
        return string(vec.begin(), vec.end());        
    }
};