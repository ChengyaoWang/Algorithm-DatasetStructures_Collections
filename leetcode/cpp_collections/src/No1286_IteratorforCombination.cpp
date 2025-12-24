# include <string>
# include <vector>
# include <numeric>
using namespace std;

class CombinationIterator {
public:
    int combinationLength;
    string characters;
    vector<int> mask;
    CombinationIterator(string characters, int combinationLength) {
        vector<int> mask(combinationLength);
        iota(mask.begin(), mask.end(), 0);
        this -> mask = move(mask);
        this -> characters = move(characters);
        this -> combinationLength = move(combinationLength);
    }

    string next() {
        string ret = "";
        for (auto& i: mask)
            ret.push_back(characters[i]);
        
        int i = 0;
        for (; i < combinationLength; ++i) {
            if (mask.back() != characters.size() - 1 - i)
                break;
            mask.pop_back();
        }

        if (i == combinationLength) {
            mask.clear();
        } else {
            ++mask.back();
            for (int j = 0; j < i; ++j)
                mask.push_back(mask.back() + 1);
        }

        return ret;
    }

    bool hasNext() {
        return !mask.empty();
    }
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */