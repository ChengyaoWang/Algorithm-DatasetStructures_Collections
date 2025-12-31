# include <vector>
# include <limits>
# include <functional>
# include <iostream>

using namespace std;

class SegmentTree {
private:
    function<long long(long long, long long)> func;
    bool f_max_or_sum = false;

public:
    int n;
    vector<long long> vec;
    vector<long long> tree;
    SegmentTree(
        vector<long long> vec,
        function<long long(long long, long long)> func
    ) {
        f_max_or_sum = func(1, 1) == 1 ? true: false;

        this -> vec = vec;
        this -> n = vec.size();
        this -> tree = vector<long long>(4 * n, f_max_or_sum ? -1: 0);
        this -> func = func;

        build(0, 0, n);
    }

    long long build(int i, int l, int h) {

        if (l == h) {
            return f_max_or_sum ? -1: 0;
        }
        else if (h - l == 1) {
            tree[i] = vec[l];
            return vec[l];
        }

        // 3 + 9  = 12 / 2 -> 6, 3 ~ 6 = 3, 6 ~ 9  = 3
        // 3 + 10 = 13 / 2 -> 6, 3 ~ 6 = 3, 6 ~ 10 = 3
        // 2 + 9  = 11 / 2 -> 5, 2 ~ 5 = 3, 5 ~ 9 = 4

        int mid = (l + h) / 2;
        long long left  = build(2 * i + 1, l, mid);
        long long right = build(2 * i + 2, mid, h);
        tree[i] = func(left, right);

        return func(left, right);
    }

    long long query(
        int rl, int rh,
        int i, int l, int h
    ) {
        if (rl == l && rh == h) {
            return tree[i];
        }
        else if (rl >= h || rh <= l || rl >= rh) {
            return f_max_or_sum ? -1LL: 0LL;
        }

        int mid = (l + h) / 2;
        long long left  = query(rl, min(mid, rh), 2 * i + 1, l, mid);
        long long right = query(max(mid, rl), rh, 2 * i + 2, mid, h);
        return func(left, right);
    }

    long long update(
        long long num, int i,
        int treeIdx, int l, int h
    ) { 

        if (i < l || i >= h) {
            return tree[treeIdx];
        }
        else if (l + 1 == h) {
            tree[treeIdx] = num;
            return num;
        }

        int mid = (l + h) / 2;

        long long left  = update(num, i, 2 * treeIdx + 1, l, mid);
        long long right = update(num, i, 2 * treeIdx + 2, mid, h);

        tree[treeIdx] = func(left, right);

        return tree[treeIdx];
    }
};


class BookMyShow {
private:
    vector<long long> vec;
    SegmentTree *tree_max, *tree_sum;

public:
    int n, m;
    int minRowThreshold;
    BookMyShow(int n, int m) {
        this -> n = n;
        this -> m = m;
        this -> minRowThreshold = 0;
        this -> vec = vector<long long>(n, m);

        this -> tree_max = new SegmentTree(
            vector<long long>(n, m),
            [](long long i, long long j){return max(i, j);}
        );
        this -> tree_sum = new SegmentTree(
            vector<long long>(n, m),
            [](long long i, long long j){return i + j;}
        );
    }
    
    vector<int> gather(int k, int maxRow) {
        
        long long kll = (long long)k;
        long long cap_at_i = tree_max -> query(minRowThreshold, maxRow + 1, 0, 0, n);
        int lo = minRowThreshold + 1, hi = maxRow + 2, mid;

        if (cap_at_i < kll || lo >= hi) {
            return vector<int>{};
        }

        while (lo < hi) {
            mid = (lo + hi) / 2;
            cap_at_i = tree_max -> query(minRowThreshold, mid, 0, 0, n);
            
            if (cap_at_i < k)
                lo = mid + 1;
            else
                hi = mid;
        }        

        if (lo == maxRow + 2)
            return vector<int>{};

        long long remainder = (tree_max -> query(minRowThreshold, lo, 0, 0, n) - kll);
        int retRow = lo - 1, retCol = m - vec[lo - 1];
        tree_max -> update(remainder, lo - 1, 0, 0, n);
        tree_sum -> update(remainder, lo - 1, 0, 0, n);
        vec[lo - 1] = remainder;
        // minRowThreshold = lo - 1 + (remainder == 0 ? 1: 0);        

        return vector<int>{retRow, retCol};
    }
    
    bool scatter(int k, int maxRow) {
    
        long long kll = (long long)k;
        long long cap_at_i = tree_sum -> query(minRowThreshold, maxRow + 1, 0, 0, n);
        int lo = minRowThreshold + 1, hi = maxRow + 2, mid;

        if (cap_at_i < kll || lo >= hi)
            return false;

        while (lo < hi) {
            mid = (lo + hi) / 2;
            cap_at_i = tree_sum -> query(minRowThreshold, mid, 0, 0, n);
            
            if (cap_at_i < k)
                lo = mid + 1;
            else
                hi = mid;
        }

        if (lo == maxRow + 2)
            return false;

        long long remainder = (tree_sum -> query(minRowThreshold, lo, 0, 0, n) - kll);
        tree_max -> update(remainder, lo - 1, 0, 0, n);
        tree_sum -> update(remainder, lo - 1, 0, 0, n);
        vec[lo - 1] = remainder;
        minRowThreshold = lo - 1 + (remainder == 0 ? 1: 0);

        return true;
    }
};


/**
 * Your BookMyShow object will be instantiated and called as such:
 * BookMyShow* obj = new BookMyShow(n, m);
 * vector<int> param_1 = obj->gather(k,maxRow);
 * bool param_2 = obj->scatter(k,maxRow);
 */