# include <queue>
# include <vector>

using namespace std;

class MedianFinder {
private:
    priority_queue<int, vector<int>, less<int>> q_low;
    priority_queue<int, vector<int>, greater<int>> q_up;
public:
    MedianFinder() {
        q_low = {};
        q_up = {};
    }
    
    void addNum(int num) {

        if (q_low.empty() || num <= q_low.top()) {
            q_low.push(num);
            if (q_low.size() > q_up.size() + 1) {
                auto elem = q_low.top();
                q_low.pop();
                q_up.push(elem);
            }
        } else {
            q_up.push(num);
            if (q_up.size() > q_low.size()) {
                auto elem = q_up.top();
                q_up.pop();
                q_low.push(elem);
            }
        }
    }
    
    double findMedian() {

        if (q_low.size() == q_up.size()) {
            return (double(q_low.top()) + double(q_up.top())) / 2.;
        }

        return double(q_low.top());

    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */