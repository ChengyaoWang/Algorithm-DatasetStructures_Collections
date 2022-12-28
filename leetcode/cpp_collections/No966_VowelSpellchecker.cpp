# include <vector>
# include <string>
# include <algorithm>
# include <unordered_map>
# include <unordered_set>

using namespace std;

class Solution {
public:
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        
        unordered_map<string, vector<string>> cap;
        unordered_map<string, vector<string>> vowel;
        unordered_set<string> ori;
        unordered_set<unsigned char> vowel_set {'a', 'e', 'i', 'o', 'u'};

        for (auto &w: wordlist) {

            auto w_ori = w;
            ori.insert(w_ori);

            transform(w.begin(), w.end(), w.begin(), [](
                unsigned char c
            ){ return tolower(c); });

            if ( cap.find(w) == cap.end() ) {
                cap[w] = vector<string> {};
            }
            cap[w].push_back(w_ori);

            transform(w.begin(), w.end(), w.begin(), [vowel_set](
                unsigned char c
            ){ return vowel_set.find(c) == vowel_set.end() ? c: '*'; });

            if ( vowel.find(w) == vowel.end() ) {
                vowel[w] = vector<string> {};
            }
            vowel[w].push_back(w_ori);
        }

        vector<string> retList;
        for (auto &w: queries) {
            if ( ori.find(w) != ori.end() ) {
                retList.push_back(w);
                continue;
            }
            
            transform(w.begin(), w.end(), w.begin(), [](
                unsigned char c
            ){ return tolower(c); });

            if ( cap.find(w) != cap.end() ) {
                retList.push_back(cap[w][0]);
                continue;
            }

            transform(w.begin(), w.end(), w.begin(), [vowel_set](
                unsigned char c
            ){ return vowel_set.find(c) == vowel_set.end() ? c: '*'; });

            if ( vowel.find(w) != vowel.end() ) {
                retList.push_back(vowel[w][0]);
                continue;
            }

            retList.push_back("");
        }

        return retList;
    }
};