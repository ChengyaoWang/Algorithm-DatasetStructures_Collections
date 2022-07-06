# include <vector>
# include <string>
# include <regex>

using namespace std;

class Solution {
public:
    bool areSentencesSimilar(string sentence1, string sentence2) {

        vector<string> sen1_split = split(sentence1);
        vector<string> sen2_split = split(sentence2);

        int i, j;
        for (i = 0; i < sen1_split.size() && i < sen2_split.size(); ++i) {
            if (sen1_split[i] != sen2_split[i]) 
                break;
        }
        for (j = 0; j < sen1_split.size() && j < sen2_split.size(); ++j) {
            if (sen1_split[sen1_split.size() - 1 - j] != sen2_split[sen2_split.size() - 1 - j])
                break;
        }

        return (i + j) == (sen1_split.size() + sen2_split.size()) ||
                i == min(sen1_split.size(), sen2_split.size()) || 
                j == min(sen1_split.size(), sen2_split.size());
    }

    vector<string> split(string s) {
        smatch sm;
        regex exp("[a-zA-Z]+");
        vector<string> retList;
        
        string::const_iterator searchStart( s.cbegin() );
        while ( regex_search( searchStart, s.cend(), sm, exp ) ) {
            retList.push_back(sm[0]);
            searchStart = sm.suffix().first;
        }

        return retList;
    }
};