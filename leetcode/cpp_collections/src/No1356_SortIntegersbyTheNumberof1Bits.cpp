# include <vector>
# include <algorithm>
# include <numeric>
using namespace std;

class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        vector<int> cnt(arr.size()), idx(arr.size());
        transform(arr.begin(), arr.end(), cnt.begin(), [](int a) {
            int cnt = 0;
            while (a) {cnt += a % 2; a >>= 1;}
            return cnt;
        });
        iota(idx.begin(), idx.end(), 0);
        sort(idx.begin(), idx.end(), [=](int i, int j){
            if (cnt[i] == cnt[j])   return arr[i] < arr[j];
            return cnt[i] < cnt[j];
        });

        transform(idx.begin(), idx.end(), idx.begin(), [=](int i){
            return arr[i];
        });
        return idx;
    }
};