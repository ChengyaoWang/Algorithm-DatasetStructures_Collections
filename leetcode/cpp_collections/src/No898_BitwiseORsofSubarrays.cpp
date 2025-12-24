# include <vector>
# include <unordered_set>
using namespace std;

class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {

        unordered_set<int> ret, set1, set2;

        for (auto& i: arr) {
            set1.clear();
            set1.insert(i);
            for (auto& j: set2) set1.insert(i | j);
            set2 = move(set1);
            for (auto& j: set2) ret.insert(j);
        }

        return ret.size();

    }
};