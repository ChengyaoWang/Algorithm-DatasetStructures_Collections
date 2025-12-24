# include <iostream>
# include <vector>
# include <random>
# include <numeric>
# include "./src/No2286_BookingConcertTicketsinGroups.hpp"

using namespace std;

int main() {
    vector<long long> vec = {
        80, 40, 48, 33, 60,
        69,  7, 98,  4, 22,
        6,  75,  7, 94,  0,
        52, 20, 44, 76, 86
    };
    
    SegmentTree *sum_tree = new SegmentTree(vec, [](long long i, long long j){return i + j;});
    SegmentTree *max_tree = new SegmentTree(vec, [](long long i, long long j){return max(i, j);});

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distr(0, vec.size() - 1);

    for (int trial_i = 0; trial_i < 10000; ++trial_i) {

        int l = distr(gen), r = distr(gen);
        if (l > r)
            swap(l, r);
    
        long long gt_sum = accumulate(vec.begin() + l, vec.begin() + r, 0);
        long long tr_sum = sum_tree -> query(l, r, 0, 0, vec.size());

        long long gt_max = l == r ? -1: *max_element(vec.begin() + l, vec.begin() + r);
        long long tr_max = max_tree -> query(l, r, 0, 0, vec.size());

        if (gt_sum != tr_sum) {
            std::cout << "Error of iter " << trial_i << " in sum tree" << endl;
            std::cout << "\t" << l << "|" << r << "|" << gt_sum << "|" << tr_sum << endl;
        }
        if (gt_max != tr_max) {
            std::cout << "Error of iter " << trial_i << " in max tree" << endl;
            std::cout << "\t" << l << "|" << r << "|" << gt_max << "|" << tr_max << endl;
        }

        int rd = distr(gen);
        if (rd % 2 == 0) {
            int idx = distr(gen);
            long long elem = distr(gen);
            // std::cout << "Update call at iter" << trial_i << " <" << idx << "|" << elem << endl;
            vec[idx] = elem;
            sum_tree -> update(elem, idx, 0, 0, vec.size());
            max_tree -> update(elem, idx, 0, 0, vec.size());
        }
    }
    return 0;
}
