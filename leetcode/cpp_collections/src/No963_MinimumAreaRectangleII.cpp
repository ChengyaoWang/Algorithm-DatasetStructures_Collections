# include <vector>
# include <map>
# include <limits>
# include <complex>

using namespace std;

typedef vector<pair<int, int>> pl;

class Solution {
private:

public:
    double minAreaFreeRect(vector<vector<int>>& points) {
        
        map<pair<double, double>, pl> seen;
        vector<pair<double, double>> points_com;
        for (auto &i: points)
            points_com.push_back(
                pair<double, double>(double(i[0]), double(i[1]))
            );

        for (int i = 0; i < points_com.size() - 1; ++i) {
            for (int j = i + 1; j < points_com.size(); ++j) {
                
                auto c = pair<double, double> {
                    (points_com[i].first + points_com[j].first) / 2.,
                    (points_com[i].second + points_com[j].second) / 2.,
                };
                if (seen.find(c) == seen.end()) {
                    seen[c] = pl {};
                }
                seen[c].push_back(pair<int, int> {i, j});
            }
        }

        double retAns = numeric_limits<double>::max();
        auto isOrth = [](
            pair<double, double> p1,
            pair<double, double> p2, 
            pair<double, double> p3
        ) {
            return (
                (p1.first - p2.first) * (p3.first - p2.first) +
                (p1.second - p2.second) * (p3.second - p2.second)
            ) == 0;
        };


        for (auto &ps: seen) {
            auto pc = ps.first;
            auto ps_list = ps.second;

            for (int i = 0; i < ps_list.size() - 1; ++i) {
                for (int j = i + 1; j < ps_list.size(); ++j) {
                    auto p1 = points_com[ps_list[i].first];
                    auto p2 = points_com[ps_list[j].first];
                    auto p3 = points_com[ps_list[i].second];
                    if (isOrth(p1, p2, p3)) {
                        auto x1 = p2.first - p1.first;
                        auto x2 = p2.second - p1.second;
                        auto x3 = p2.first - p3.first;
                        auto x4 = p2.second - p3.second;
                        retAns = min(retAns, sqrt(x1 * x1 + x2 * x2) * sqrt(x3 * x3 + x4 * x4));
                    }
                }
            }
        }

        return retAns == numeric_limits<double>::max() ? 0.: retAns;
    }
};