# include <vector>

using namespace std;


class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        
        double x = 0., y = 0.;
        if (xCenter < x1) {
            x = x1 - xCenter;
        } else if (xCenter > x2) {
            x = x2 - xCenter;
        }
        if (yCenter < y1) {
            y = y1 - yCenter;
        } else if (yCenter > y2) {
            y = y2 - yCenter;
        }

        return x * x + y * y <= radius * radius;
    }
};