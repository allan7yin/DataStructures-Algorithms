package SlidingWindow

// time complexity -> O(n)
func characterReplacement(s string, k int) int {
    maxLength := 0
    l := 0
    maxFreq := 0
    freqMap := make(map[rune]int)

    for r := 0; r < len(s); r++ {
        // re-compute most frequent character in current window
        freqMap[rune(s[r])]++
        maxFreq = max(maxFreq, freqMap[rune(s[r])])
        
        for r - l + 1 - maxFreq > k {
            freqMap[rune(s[l])]--
            l++
        }
        
        maxLength = max(maxLength, r - l + 1)
    }
    return maxLength
}
