type Bank struct {
    bank []int64
}


func Constructor(balance []int64) Bank {
    return Bank{bank: balance}
}


func (this *Bank) Transfer(account1 int, account2 int, money int64) bool {
    if account1 > len(this.bank) || account2 > len(this.bank) {
        return false
    }
    if this.bank[account1-1] < money {
        return false
    }
    this.bank[account1-1] -= money
    this.bank[account2-1] += money
    return true
}


func (this *Bank) Deposit(account int, money int64) bool {
    if account > len(this.bank) {
        return false
    }
    this.bank[account-1] += money
    return true
}


func (this *Bank) Withdraw(account int, money int64) bool {
    if account > len(this.bank) {
        return false
    }
    if this.bank[account-1] < money {
        return false
    }
    this.bank[account-1] -= money
    return true
}


/**
 * Your Bank object will be instantiated and called as such:
 * obj := Constructor(balance);
 * param_1 := obj.Transfer(account1,account2,money);
 * param_2 := obj.Deposit(account,money);
 * param_3 := obj.Withdraw(account,money);
 */