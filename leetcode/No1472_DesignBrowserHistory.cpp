# include <vector>
# include <string>
using namespace std;


class BrowserHistory {
private:
    vector<string> l;
    int ptr;
public:
    BrowserHistory(string homepage) {
        this -> l = {homepage};
        this -> ptr = 0;
    }
    
    void visit(string url) {
        (this -> l).resize((this -> ptr)++ + 1);
        (this -> l).push_back(url);
    }
    
    string back(int steps) {
        this -> ptr = max(this -> ptr - steps, 0);
        return (this -> l)[this -> ptr];
    }
    
    string forward(int steps) {
        this -> ptr = min(this -> ptr + steps, int((this -> l).size()) - 1);
        return (this -> l)[this -> ptr];
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */