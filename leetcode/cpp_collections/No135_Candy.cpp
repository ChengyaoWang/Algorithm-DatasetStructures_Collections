# include <vector>

using namespace std;

class Solution {
public:
    int candy(vector<int>& ratings) {
		
		int cnt = 1, consec_drop = 1, prev_no = 1;
        int peak = 1;
		
		for (int i = 1; i < ratings.size(); ++i) {
			if (ratings[i - 1] > ratings[i]) {
                if (prev_no == 1) {
                    cnt += consec_drop;
                    if (peak == consec_drop) {
                        cnt++;
                        peak++;
                    }
                } else {
                    ++cnt;
                }
                ++consec_drop;
                prev_no = 1;
			} else {
				consec_drop = 1;
				cnt += ++prev_no;
                peak = prev_no;
			}
		}

		return cnt;
    }
};