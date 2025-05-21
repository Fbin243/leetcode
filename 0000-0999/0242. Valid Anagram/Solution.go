func isAnagram(s string, t string) bool {
	if len(s) != len(t) {
		return false
	}
	freq := map[int]int{}
	for i := 0; i < len(s); i++ {
		freq[int(s[i])]++
		freq[int(t[i])]--
	}

	for _, f := range freq {
		if f != 0 {
			return false
		}
	}

	return true
}
