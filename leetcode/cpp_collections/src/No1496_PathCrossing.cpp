# include <string>
# include <set>

using namespace std;

class Solution {
public:
    bool isPathCrossing(string path) {
        
        int h = 0, v = 0;
        set<int> mem = {0};

        for (char& c: path) {
            switch (c) {
                case 'N':
                    ++v;
                    break;
                case 'S':
                    --v;
                    break;
                case 'E':
                    ++h;
                    break;
                case 'W':
                    --h;
                    break;
            }
            if (mem.find(10000 * h + v) != mem.end())
                return true;
            mem.insert(10000 * h + v);
        }
        return false;
    }
};