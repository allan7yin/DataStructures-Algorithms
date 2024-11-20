package SlidingWindow

func checkInclusion(s1 string, s2 string) bool {
    
    var s1Mp [26]int
    var s2Mp [26]int

    for _, ch := range s1 {
        s1Mp[ch-'a']++
    }

    l := 0
    for r, ch := range s2 {
        s2Mp[ch - 'a']++
        if r - l + 1 > len(s1) {
            s2Mp[s2[l] - 'a']--
            l++
        }

        if s1Mp == s2Mp {
            return true
        }
    }
    return false
}
