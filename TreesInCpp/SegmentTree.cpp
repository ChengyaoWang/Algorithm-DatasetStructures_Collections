/*
    This Implementation is Used for LeetCode No. 1649 'Create Sorted Array through Instructions'
        -> Neat Solution Process for Update & Query
*/
# include <vector>

using namespace std;

class SegmentTree{

private:
    int m;
    vector<int> segArr;
    
public:
    SegmentTree(vector<int>& arr){
        this -> segArr = arr;
        m = arr.size();
    }
    SegmentTree(int n){
        this -> segArr = vector<int> (n);
    }

    void update(int idx){
        for(idx += m; idx > 0; idx >>= 1)
            ++segArr[idx];
    }
    
    int query(int low, int up){
        int result = 0;
        for (low += m, up += m; low < up; low >>= 1, up >>= 1) {
            if ((low & 1) == 1) result += segArr[low++];
            if ((up & 1) == 1) result += segArr[--up];
        }
        return result;
    }
};