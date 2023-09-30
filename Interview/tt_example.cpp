# include <vector>
using namespace std;

int CountTriangles(vector<int> A) {
 
    int n = A.size(), count = 0;
    sort(A.begin(), A.end());
    for (int i = n - 1; i >= 1; i--) {
        int l = 0, r = i - 1;
        while (l < r) {
            if (A[l] + A[r] > A[i]) {
                count += r-- - l;
            }
            else
                l++;
        }
    }

    return count;
}