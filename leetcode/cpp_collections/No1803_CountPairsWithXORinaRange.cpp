# include <vector>
using namespace std;

class Trie {
private:
    vector<Trie*> child;
    int degree;
public:
    Trie() {
        this -> child = vector<Trie*>(2, nullptr);
        this -> degree = 0;
    }

    void insert(int elem, int depth) {
        ++degree;
        if (depth == -1) {
            return ;
        }
        int dir = (elem >> depth) & 1;
        if (child[dir] == nullptr) {
            child[dir] = new Trie();
        }
        child[dir] -> insert(elem, depth - 1);
    }

    int findLess(int tgt, int n, int depth) {
        if (depth == -1)
            return degree;
        int a = (tgt >> depth) & 1;
        int b = (n >> depth) & 1;
        int d1 = a xor b;
        int t1 = child[d1] ? child[d1] -> findLess(tgt, n, depth - 1): 0;
        if (a == 1)
            t1 += child[b] ? child[b] -> degree: 0;
        return t1;
    }
};

class Solution {
public:
    int countPairs(vector<int>& nums, int low, int high) {

        Trie t;
        int ret = 0;
        for (auto n: nums) {
            ret += t.findLess(high, n, 15) - t.findLess(low - 1, n, 15);
            t.insert(n, 15);
        }

        return ret;
    }
};