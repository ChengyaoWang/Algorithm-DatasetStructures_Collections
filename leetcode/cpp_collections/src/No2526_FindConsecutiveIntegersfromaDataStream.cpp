# include <vector>
using namespace std;

class DataStream {
public:
    int lastValid;
    int value, k;
    DataStream(int value, int k) {
        this -> value = value;
        this -> k = k;
        lastValid = 0;
    }
    
    bool consec(int num) {
        lastValid = (num == value) ? lastValid + 1: 0;
        return lastValid >= k;
    }
};

/**
 * Your DataStream object will be instantiated and called as such:
 * DataStream* obj = new DataStream(value, k);
 * bool param_1 = obj->consec(num);
 */