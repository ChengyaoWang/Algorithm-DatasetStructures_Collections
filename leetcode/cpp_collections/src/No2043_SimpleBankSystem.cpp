# include <vector>
using namespace std;

class Bank {
public:
    vector<long long> account;
    bool withinRange(int i) {
        return 1 <= i && i <= account.size();
    }
    Bank(vector<long long>& balance) {
        account.resize(balance.size());
        copy(balance.begin(), balance.end(), account.begin());        
    }
    
    bool transfer(int account1, int account2, long long money) {
        if (!withinRange(account1) || !withinRange(account2) || account[account1 - 1] < money) {
            return false;
        }
        account[account1 - 1] -= money;
        account[account2 - 1] += money;
        return true;
    }
    
    bool deposit(int account, long long money) {
        if (!withinRange(account)) {
            return false;
        }
        (this -> account)[account - 1] += money;
        return true;
    }

    bool withdraw(int account, long long money) {
        if (!withinRange(account) || (this -> account)[account - 1] < money) {
            return false;
        }
        (this -> account)[account - 1] -= money;
        return true;
    }
};

/**
 * Your Bank object will be instantiated and called as such:
 * Bank* obj = new Bank(balance);
 * bool param_1 = obj->transfer(account1,account2,money);
 * bool param_2 = obj->deposit(account,money);
 * bool param_3 = obj->withdraw(account,money);
 */