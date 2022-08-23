# include <unordered_map>
# include <set>

using namespace std;

class NumberContainers {
private:
    unordered_map<int, int> i2m;
    unordered_map<int, set<int>> m2i;
public:
    NumberContainers() {
        i2m = unordered_map<int, int> {};
        m2i = unordered_map<int, set<int>> {};
    }
    
    void change(int index, int number) {
        if (i2m.find(index) == i2m.end()) {
            i2m.insert({index, number});
            m2i[number].insert(index);   
        } else if (i2m[index] != number){
            m2i[i2m[index]].erase(index);
            if (m2i[i2m[index]].empty()) {
                m2i.erase(i2m[index]);
            }
            i2m[index] = number;
            m2i[number].insert(index);
        }
    }
    
    int find(int number) {
        if (m2i.find(number) == m2i.end()) {
            return -1;
        }
        return *m2i[number].begin();
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */