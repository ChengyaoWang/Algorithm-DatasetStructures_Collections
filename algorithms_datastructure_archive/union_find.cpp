# include <vector>
# include <numeric>

/*
    Union Find Algorithm With Rank
        -> It balances the height of trees representing each group while performing group joins
*/

class UnionFind {
private:
    std::vector<int> un, h;
public:
    UnionFind(int n) {
        this -> un = std::vector<int>(n);
        this -> h = std::vector<int>(n, 0);
        iota(this -> un.begin(), this -> un.end(), 0);
    }

    int find(int x) {
        while (x != un[x])
            x = un[x];
        return x;
    }

    void joinWithRank(int x, int y) {
        int xGroup = find(x), yGroup = find(y);
        if (xGroup == yGroup)
            return ;
        
        if (h[xGroup] < h[yGroup]) {
            un[xGroup] = yGroup;
        } else if (h[xGroup] > h[yGroup]){
            un[yGroup] = xGroup;
        } else {
            un[yGroup] = xGroup;
            ++h[xGroup];
        }

        return ;
    }
}
;
