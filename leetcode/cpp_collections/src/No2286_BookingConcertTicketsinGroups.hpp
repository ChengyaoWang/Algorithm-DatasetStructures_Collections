# include <vector>
# include <limits>
# include <functional>

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
