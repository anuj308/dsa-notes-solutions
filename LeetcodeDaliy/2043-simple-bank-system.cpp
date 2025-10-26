
// LeetCode Daily: 2025-10-26
// Problem: 2043. Simple Bank System
// URL: https://leetcode.com/problems/simple-bank-system
// Difficulty: MEDIUM

// ==================== C++ SOLUTION ====================
//Tc-O(n), Sc-O(n)
class Bank {
public:
    vector<long long> balance;
    int n;
    Bank(vector<long long>& balance) {
        this->balance = balance;
        this->n = balance.size();      
    }
    
    bool transfer(int account1, int account2, long long money) {
        if(account1>=1 && account1<=this->n && account2>=1 && account2<=this->n && balance[account1-1]>=money){
            this->balance[account1-1]-=money;
            this->balance[account2-1]+=money;
            return true;
        }
        return false;
    }
    
    bool deposit(int account, long long money) {
        if(account>=1 && account<=this->n){w
            this->balance[account-1]+=money;
            return true;
        }
        return false;
    }
    
    bool withdraw(int account, long long money) {
        if(account>=1 && account<=this->n && this->balance[account-1]>=money){
            this->balance[account-1]-=money;
            return true;
        }
        return false;
    }
};

/**
 * Your Bank object will be instantiated and called as such:
 * Bank* obj = new Bank(balance);
 * bool param_1 = obj->transfer(account1,account2,money);
 * bool param_2 = obj->deposit(account,money);
 * bool param_3 = obj->withdraw(account,money);
 */
/* ==================== PYTHON SOLUTION ====================


/* ==================== JAVA SOLUTION ====================
class Bank {
    long[] balance;
    int n;
    public Bank(long[] balance) {
        this.balance = balance;
        this.n = balance.length;       
    }
    
    public boolean transfer(int account1, int account2, long money) {
        if(account1>=1 && account1<=this.n && account2>=1 && account2<=this.n && balance[account1-1]>=money){
            this.balance[account1-1]-=money;
            this.balance[account2-1]+=money;
            return true;
        }
        return false;
    }
    
    public boolean deposit(int account, long money) {
        if(account>=1 && account<=this.n){
            this.balance[account-1]+=money;
            return true;
        }
        return false;
    }
    
    public boolean withdraw(int account, long money) {
        if(account>=1 && account<=this.n && this.balance[account-1]>=money){
            this.balance[account-1]-=money;
            return true;
        }
        return false;
    }
}

/*
*
 * Your Bank object will be instantiated and called as such:
 * Bank obj = new Bank(balance);
 * boolean param_1 = obj.transfer(account1,account2,money);
 * boolean param_2 = obj.deposit(account,money);
 * boolean param_3 = obj.withdraw(account,money);
 */
