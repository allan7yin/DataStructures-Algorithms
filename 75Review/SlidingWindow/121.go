func maxProfit(prices []int) int {
    l := 0
    profit := 0

    for r := 0; r < len(prices); r++ {
        if prices[r] > prices[l] {
            profit = max(profit, prices[r] - prices[l])
        } else {
            l = r
        }
    }
    return profit
}
