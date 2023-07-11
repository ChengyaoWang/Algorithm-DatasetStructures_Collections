# include <vector>
# include <unordered_map>
using namespace std;

class DetectSquares {
public:
    int fetchKey(unordered_map<int, int>& m, int k) {
        if (m.find(k) == m.end())
            return 0;
        return m.at(k);
    }
    int findKey(int i, int j) {
        if (i < 0 || j < 0 || i > 1000 || j > 1000)
            return -1;
        return 1001 * i + j;
    }

    pair<int, int> resolveKey(int i) {
        if (i < 0)
            return make_pair(-1, -1);
        return make_pair(i / 1001, i % 1001);
    }

    unordered_map<int, int> cnter;
    DetectSquares() {
        cnter.clear();
    }

    void add(vector<int> point) {
        auto p = findKey(point[0], point[1]);
        if (p >= 0) 
            ++cnter[p];
    }

    int count(vector<int> point) {
        int ret = 0;
        int i = point[0], j = point[1];
        for (auto kv: cnter) {
            auto p = resolveKey(kv.first);
            if (p.second == j) {
                auto delta = p.first - i;
                if (delta == 0) continue;
                ret += kv.second * (
                    fetchKey(cnter, findKey(i, j + delta)) * 
                    fetchKey(cnter, findKey(p.first, p.second + delta)) + 
                    fetchKey(cnter, findKey(i, j - delta)) * 
                    fetchKey(cnter, findKey(p.first, p.second - delta))
                );
            }
        }

        return ret;        
    }
};

/**
 * Your DetectSquares object will be instantiated and called as such:
 * DetectSquares* obj = new DetectSquares();
 * obj->add(point);
 * int param_2 = obj->count(point);
 */