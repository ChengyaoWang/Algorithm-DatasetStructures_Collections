# include <vector>
# include <string>
# include <algorithm>
# include <unordered_map>
using namespace std;

struct ExtraLongInt {
    vector<long long> d;

    ExtraLongInt(): d(vector<long long>(1000, 0LL)) {}
    ExtraLongInt(vector<long long> d_): d(d_) {}

    ExtraLongInt operator&(const ExtraLongInt& rhs) {
        vector<long long> result(1000);
        transform(
            (this -> d).begin(), (this -> d).end(),
            rhs.d.begin(), result.begin(),
            [](long long x, long long y) {return x & y;}
        );
        return ExtraLongInt(result);
    }

    bool operator==(const ExtraLongInt rhs) {
        bool ret = true;
        for (int i = 0; i < 1000; ++i) {
            ret &= ((this -> d)[i] == rhs.d[i]);
        }
        return ret;
    }

    void set(int pos) {
        int group = pos / 64, groupI = pos % 64;
        d[group] |= (1LL << groupI);
    }
};

class Solution {
public:
    vector<int> peopleIndexes(vector<vector<string>>& favoriteCompanies) {

        unordered_map<string, int> encMem = {};
        vector<vector<int>> favoriteCompaniesEnc = {};
        unordered_map<int, int> isSubset = {};

        for (int i = 0; i < favoriteCompanies.size(); ++i) {
            vector<int> favoriteCompanyEnc_I = {};

            for (auto& comp: favoriteCompanies[i]) {
                if (encMem.find(comp) == encMem.end()) {
                    int pos = encMem.size();
                    encMem.insert({comp, pos});
                }
                favoriteCompanyEnc_I.push_back(encMem[comp]);
            }

            sort(favoriteCompanyEnc_I.begin(), favoriteCompanyEnc_I.end());
            
            for (int j = 0; j < favoriteCompaniesEnc.size(); ++j) {
                vector<int> listA = favoriteCompaniesEnc[j];
                vector<int> listB = favoriteCompanyEnc_I;
                int subsetI = j;
                if (listA.size() == listB.size())
                    continue;
                else if (listA.size() > listB.size()) {
                    swap(listA, listB);
                    subsetI = i;
                }

                int ii = 0;
                for (int jj = 0; jj < listB.size(); ++jj) {
                    if (listA[ii] != listB[jj])
                        continue;
                    if (++ii == listA.size()) {
                        isSubset.insert({subsetI, 1});
                        break;
                    }
                }
            }
            
            favoriteCompaniesEnc.push_back(favoriteCompanyEnc_I);
        }

        vector<int> ret = {};
        for (int i = 0; i < favoriteCompanies.size(); ++i) {
            if (isSubset.find(i) == isSubset.end()) {
                ret.push_back(i);
            }
        }

        return ret;
    }
};