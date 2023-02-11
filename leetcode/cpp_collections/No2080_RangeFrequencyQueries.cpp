# include <vector>
# include <unordered_map>
using namespace std;

class RangeFreqQuery {
private:
    unordered_map<int, vector<int>> m;
public:
    RangeFreqQuery(vector<int>& arr) {
        this -> m = {};
        for (int i = 0; i < arr.size(); ++i) {
            (this -> m)[arr[i]].push_back(i);
        }
    }
    
    int query(int left, int right, int value) {
        vector<int>& a = (this -> m)[value];
        return upper_bound(a.begin(), a.end(), right) - 
            lower_bound(a.begin(), a.end(), left);
    }
};

/**
 * Your RangeFreqQuery object will be instantiated and called as such:
 * RangeFreqQuery* obj = new RangeFreqQuery(arr);
 * int param_1 = obj->query(left,right,value);
 */