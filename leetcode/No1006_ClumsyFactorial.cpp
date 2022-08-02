
class Solution {
public:
    int clumsy(int n) {
    
        int retVal = 0, tmpVal = n;
        for (int i = n - 1; i > 0; --i) {
            switch ((n - i) % 4) {
            case 1:
                tmpVal *= i;
                break;
            case 2:
                tmpVal /= i;
                break;
            case 3:
                retVal += tmpVal + i;
                tmpVal = 0;
                break;
            default:
                tmpVal = -i;
                break;
            }
        }

        retVal += tmpVal;
        return retVal;
    }
};