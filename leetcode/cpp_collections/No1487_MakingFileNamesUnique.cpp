# include <vector>
# include <string>
# include <unordered_map>

class Solution {
public:
    std::vector<std::string> getFolderNames(std::vector<std::string>& names) {
        std::unordered_map<std::string, int> map;
        std::vector<std::string> retList;
        std::string tmpS;
        int ii;

        for (auto&i: names) {
            tmpS = i;
            if (map.find(tmpS) == map.end()) {
                map.insert({tmpS, 1});
            } else {
                ii = map[tmpS];
                while (map.find(tmpS + "(" + std::to_string(ii) + ")") != map.end()) {
                    ++ii;
                }
                map[tmpS] = ii;
                tmpS = tmpS + "(" + std::to_string(ii) + ")";
                map.insert({tmpS, 1});
            }
            retList.push_back(tmpS);            
        }

        return retList;
    }
};