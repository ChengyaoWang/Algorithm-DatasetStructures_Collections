# include <vector>
# include <string>

using namespace std;

class Solution {
public:
    int find(vector<int>* uf, int i) {
        return (*uf)[i] == i ? i: find(uf, (*uf)[i]);
    }

    bool equationsPossible(vector<string>& equations) {
        vector<int> uf(26);
        for (int i = 0; i < 26; ++i){
            uf[i] = i;
        }
        for (auto &eq_i: equations) {
            if (eq_i.at(1) == '=')
                uf[find(&uf, eq_i.at(0) - 'a')] = find(&uf, eq_i.at(3) - 'a');
        }
        for (auto &eq_i: equations) {
            if (eq_i.at(1) == '!' && find(&uf, eq_i.at(0) - 'a') == find(&uf, eq_i.at(3) - 'a')) 
                return false;
        }

        return true;
    }
};