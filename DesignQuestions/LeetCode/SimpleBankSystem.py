class Bank:
    def __init__(self, balance: List[int]):
        self.accountBalance = balance

    def transfer(self, account1: int, account2: int, money: int) -> bool:
        # check if the given account numbers are valid
        if (
            account1 > len(self.accountBalance)
            or account1 < 0
            or account2 > len(self.accountBalance)
            or account2 < 0
        ):
            return False

        if self.accountBalance[account1 - 1] >= money:
            self.accountBalance[account1 - 1] -= money
            self.accountBalance[account2 - 1] += money
            return True
        return False

    def deposit(self, account: int, money: int) -> bool:
        if account > len(self.accountBalance) or account < 0:
            return False

        self.accountBalance[account - 1] += money
        return True

    def withdraw(self, account: int, money: int) -> bool:
        if (
            account > len(self.accountBalance)
            or account < 0
            or self.accountBalance[account - 1] < money
        ):
            return False

        self.accountBalance[account - 1] -= money
        return True


# Your Bank object will be instantiated and called as such:
# obj = Bank(balance)
# param_1 = obj.transfer(account1,account2,money)
# param_2 = obj.deposit(account,money)
# param_3 = obj.withdraw(account,money)
