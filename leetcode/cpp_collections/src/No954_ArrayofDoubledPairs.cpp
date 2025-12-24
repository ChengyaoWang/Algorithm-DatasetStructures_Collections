# include <vector>
# include <unordered_map>

using namespace std;

class Solution {
public:
    bool canReorderDoubled(vector<int>& arr) {
        unordered_map<int, int> cnter;
        for (auto& i: arr) {
            ++cnter[i];
        }
        
        auto mySort = [](int a, int b) -> bool {
            return abs(a) > abs(b);
        };

        make_heap(arr.begin(), arr.end(), mySort);

        int elem;
        while (!arr.empty()) {
            pop_heap(arr.begin(), arr.end(), mySort);
            elem = arr.back();
            arr.pop_back();

            cnter[2 * elem] -= cnter[elem];
            if (cnter[2 * elem] < 0) {
                return false;
            }
        }
        
        return true;
    }
};