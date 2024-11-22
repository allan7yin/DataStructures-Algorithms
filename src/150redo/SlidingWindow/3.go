package SlidingWindow

func lengthOfLongestSubstring(s string) int {
    freq := make(map[rune]int)
    l, maxLength := 0, 0

    for r := 0; r < len(s); r++ {
      freq[rune(s[r])]++

      for freq[rune(s[r])] > 1 {
        // means this character has been seen, while this is ok, move left pointer
        freq[rune(s[l])]--
        l++
      }
      maxLength = max(maxLength, r - l + 1)
    } 

    return maxLength
}
