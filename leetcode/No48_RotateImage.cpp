# include <vector>

using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {

        int N = matrix.size();
        double center = double(N - 1) / 2.;
        for (double i = center; i >= 0.; --i) {
            for (double j = center; j > 0.; --j) {
                auto elem = matrix[int(center - i)][int(center - j)];
                matrix[int(center - i)][int(center - j)] = matrix[int(center + j)][int(center - i)];
                matrix[int(center + j)][int(center - i)] = matrix[int(center + i)][int(center + j)];
                matrix[int(center + i)][int(center + j)] = matrix[int(center - j)][int(center + i)];
                matrix[int(center - j)][int(center + i)] = elem;
            }
        }
    }
};