# include <vector>
# include <string>
# include <iterator>

using namespace std;

class OrderedStream {
private:
    vector<string> buffer;
    vector<string>::iterator ptr;
public:
    OrderedStream(int n) {
        this -> buffer = vector<string>(n);
        this -> ptr = (this -> buffer).begin();
    }
    
    vector<string> insert(int idKey, string value) {
        vector<string> retList;
        (this -> buffer)[idKey - 1] = value;

        while (this -> ptr != this -> buffer.end() && !(*this -> ptr).empty()) {
            retList.push_back(*this -> ptr);
            ++this -> ptr;
        }
        return retList;
    }
};

/**
 * Your OrderedStream object will be instantiated and called as such:
 * OrderedStream* obj = new OrderedStream(n);
 * vector<string> param_1 = obj->insert(idKey,value);
 */