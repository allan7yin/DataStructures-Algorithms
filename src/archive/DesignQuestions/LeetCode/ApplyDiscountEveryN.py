from typing import List


class Cashier:

    def __init__(self, n: int, discount: int, products: List[int], prices: List[int]):
        self.n = n
        self.customers = 0
        self.discount = discount
        # create hashmap of productId to price
        self.product_price = {}

        for i in range(len(products)):
            self.product_price[products[i]] = prices[i]

    def getBill(self, product: List[int], amount: List[int]) -> float:
        bill = 0

        for i in range(len(product)):
            bill += self.product_price[product[i]] * amount[i]

        self.customers += 1

        if self.customers % self.n == 0:
            # earned the discount
            bill *= (100 - self.discount) / 100

        return bill


# Your Cashier object will be instantiated and called as such:
# obj = Cashier(n, discount, products, prices)
# param_1 = obj.getBill(product,amount)
