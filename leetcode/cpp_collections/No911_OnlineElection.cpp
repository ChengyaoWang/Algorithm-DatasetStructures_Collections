# include <vector>
# include <unordered_map>
using namespace std;

class TopVotedCandidate {
public:
    vector<pair<int, int>> mem = {};
    TopVotedCandidate(vector<int>& persons, vector<int>& times) {
        int n = persons.size();
        unordered_map<int, int> votes = {};
        mem = {make_pair(-1, -1)};
        int mostSoFar = -1;
        for (int i = 0; i < n; ++i) {
            ++votes[persons[i]];
            if (votes[persons[i]] >= mostSoFar) {
                mem.push_back(make_pair(times[i], persons[i]));
                mostSoFar = max(mostSoFar, votes[persons[i]]);
            }
        }
    }
    
    int q(int t) {

        auto it = upper_bound(mem.begin(), mem.end(), t,
            [](int tgt_v, const pair<int, int>& p) {
                return tgt_v < p.first;
            }
        );

        it = prev(it);

        return (*it).second;        
    }
};

/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * TopVotedCandidate* obj = new TopVotedCandidate(persons, times);
 * int param_1 = obj->q(t);
 */