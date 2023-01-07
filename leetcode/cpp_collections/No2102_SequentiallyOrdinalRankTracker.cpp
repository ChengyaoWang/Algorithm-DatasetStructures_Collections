# include <set>
# include <string>
using namespace std;

class SORTracker {
public:
    set<pair<int, string>> s;
    set<pair<int, string>>::iterator it;
    SORTracker() {
        this -> s = {};
        this -> it = (this -> s).begin();
    }
    
    void add(string name, int score) {
        auto elem = pair<int, string> {-score, name};
        (this -> s).insert(elem);
        if (elem < *(this -> it))
            --(this -> it);
    }
    
    string get() {
        auto elem = *(this -> it);
        ++(this -> it);
        return elem.second;
    }
};

/**
 * Your SORTracker object will be instantiated and called as such:
 * SORTracker* obj = new SORTracker();
 * obj->add(name,score);
 * string param_2 = obj->get();
 */