# include <map>

using namespace std;

class MyCalendarThree {
map<int, int> m;
int maxK;
public:
    MyCalendarThree() {
        this -> m = {{-1, 0}};
        this -> maxK = 0;
    }
    
    int book(int start, int end) {

        auto it_s = m.emplace(start, (--m.upper_bound(start)) -> second);
        auto it_e = m.emplace(end, (--m.upper_bound(end)) -> second);

        for (auto it = it_s.first; it != it_e.first; ++it) {
            maxK = max(maxK, ++(it -> second));
        }
        return maxK;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */