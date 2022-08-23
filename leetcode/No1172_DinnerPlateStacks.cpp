# include <stack>
# include <queue>
# include <vector>

using namespace std;

class DinnerPlates {
private:
    int cap, ptr_right;
    priority_queue<int, vector<int>, greater<int>> pq;
    vector<stack<int>> row;

public:
    DinnerPlates(int capacity) {
        cap = capacity;
        pq = priority_queue<int, vector<int>, greater<int>> {};
        row = vector<stack<int>> {};
    }
    
    void push(int val) {
        while (!pq.empty() && (row.size() <= pq.top() || row[pq.top()].size() == cap)) {
            pq.pop();
        }

        if (pq.empty()) {
            pq.push(row.size());
            row.push_back(stack<int> {});
        }

        row[pq.top()].push(val);
    }

    int pop() {
        // Find the RightMost Stack to pop
        while (!row.empty() && row.back().empty()) {
            row.pop_back();
        }
        // If None Left
        if (row.empty()) {
            return -1;
        }

        auto elem = row.back().top();
        row.back().pop();
        pq.push(row.size() - 1);

        return elem;
    }
    
    int popAtStack(int index) {
        if (row.size() < index || row[index].empty()) {
            return -1;
        }

        auto elem = row[index].top();
        row[index].pop();
        pq.push(index);

        return elem;
    }
};

/**
 * Your DinnerPlates object will be instantiated and called as such:
 * DinnerPlates* obj = new DinnerPlates(capacity);
 * obj->push(val);
 * int param_2 = obj->pop();
 * int param_3 = obj->popAtStack(index);
 */