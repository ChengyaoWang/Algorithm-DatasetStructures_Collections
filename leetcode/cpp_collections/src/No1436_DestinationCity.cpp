# include <string>
# include <vector>
# include <unordered_set>
using namespace std;

class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        
        unordered_set<string> ingoing, yet;

        for (auto& p: paths) {
            ingoing.insert(p[0]);
            if (yet.find(p[0]) != yet.end())
                yet.erase(p[0]);
            
            if (ingoing.find(p[1]) == ingoing.end())
                yet.insert(p[1]);
        }

        return *yet.begin();
    }
};