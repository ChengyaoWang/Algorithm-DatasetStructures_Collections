# include <vector>
# include <unordered_map>

using namespace std;

class FreqStack {
int maxFreq;
unordered_map<int, int> num2freq;
unordered_map<int, vector<int>> freq2num;

public:
    FreqStack() {
        this -> maxFreq = 0;
        this -> num2freq = {};
        this -> freq2num = {};
    }
    
    void push(int val) {
        auto freqVal = ++num2freq[val];
        if (freqVal > maxFreq) {
            freq2num.insert({++maxFreq, {}});
        }
        freq2num[freqVal].push_back(val);
    }

    int pop() {

        auto elem = freq2num[maxFreq].back();
        --num2freq[elem];
        freq2num[maxFreq].pop_back();
        if (freq2num[maxFreq].empty()) {
            freq2num.erase(maxFreq--);
        }

        return elem;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */ 