def calculate_ways(word_len, max_vowels):
    mod = int(1e9 + 7)
    dp = [[0] * (max_vowels + 1) for _ in range(word_len + 1)]
    dp[0][0] = 1
    for i in range(1, word_len + 1):
        dp[i][0] = sum(dp[i - 1][v] * 21 for v in range(max_vowels + 1)) % mod
        for v in range(1, max_vowels + 1):
            dp[i][v] = (dp[i - 1][v - 1] * 5) % mod
    num_ways = sum(dp[word_len][v] for v in range(max_vowels + 1)) % mod
    return num_ways
