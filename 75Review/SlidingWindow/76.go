package SlidingWindow

/*
- Initial Idea: We want to find the minimum length substring in t that has all the characters (including repeated ones) of s
- We move pointer r rightwards as normal
- when should we move left pointer? => if left pointer is only when we have found a match, keep moving it left until no longer valid
- keep track of matching with `need` and `have` counts
- time complexity is O(n)
*/
import (
  "math"
)

func minWindows(s string, t string) string {
  solL, solR, minLength := 0, 0, math.MaxInt
  tMap := make(map[rune]int)
  window := make(map[rune]int)

  for _, ch := range t {
    tMap[ch]++
  }

  l, have, need := 0, 0, len(tMap)

  for r, ch := range s {
    if _, ok := tMap[ch]; ok {
      window[ch]++
      if window[ch] == tMap[ch] {
        have++
      }
    }

    for have == need {
      if r - l + 1 < minLength {
        solL = l
        solR = r
        minLength = r - l + 1
      }

      leftChar := rune(s[l])
      if _, ok := tMap[leftChar]; ok {
        if window[leftChar] == tMap[leftChar] {
          have--
        }
        window[leftChar]--
      }

      l++
    }
  }

  if minLength == math.MaxInt {
    return ""
  }
  return s[solL : solR + 1]
}
