# include <vector>
# include <utility>
# include <unordered_set>
using namespace std;

class Solution {
private:
    bool withinRange(int i, int j) {
        return 0 <= i && i < 1000000LL && 0 <= j && j < 1000000LL;
    }
    void addKey(int i, int j, unordered_set<long long>& t) {
        t.insert(1000000LL * i + j);
    }
    bool inSet(int i, int j, unordered_set<long long>& t) {
        return t.find(1000000LL * i + j) != t.end();
    }
    bool dfsRestricted(
        int i, int j, int& step,
        pair<int, int> target,
        unordered_set<long long>& seen,
        unordered_set<long long>& block
    ) {
        if (!withinRange(i, j)) {
            return false;
        }
        if (inSet(i, j, block) || inSet(i, j, seen)) {
            return false;
        }
        if ((step > 20000) || (make_pair(i, j) == target))  {
            return true;
        }

        ++step;
        addKey(i, j, seen);
        bool ret = false;
        ret |= dfsRestricted(i + 1, j, step, target, seen, block);
        ret |= dfsRestricted(i - 1, j, step, target, seen, block);
        ret |= dfsRestricted(i, j + 1, step, target, seen, block);
        ret |= dfsRestricted(i, j - 1, step, target, seen, block);
        return ret;
    }
public:
    bool isEscapePossible(vector<vector<int>>& blocked, vector<int>& source, vector<int>& target) {
        
        unordered_set<long long> seen, block;
        for (auto& vec: blocked) {
            addKey(vec[0], vec[1], block);
        }
        
        pair<int, int> p1 = make_pair(source[0], source[1]);
        pair<int, int> p2 = make_pair(target[0], target[1]);

        int step = 0;
        bool src = dfsRestricted(source[0], source[1], step, p2, seen, block);
        
        step = 0;
        seen.clear();
        bool tar = dfsRestricted(target[0], target[1], step, p1, seen, block);
        return src && tar;
    }
};