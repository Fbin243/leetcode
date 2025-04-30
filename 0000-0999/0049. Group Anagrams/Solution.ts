function groupAnagrams(strs: string[]): string[][] {
	const freqMap = new Map<string, Array<string>>();

	for (const s of strs) {
		const freq = new Array(26).fill(0);
		for (const c of s) {
			freq[c.charCodeAt(0) - "a".charCodeAt(0)]++;
		}

		const key = freq.join("#");
		if (!freqMap.has(key)) freqMap.set(key, [s]);
		else freqMap.get(key)!.push(s);
	}

	const ans = [];
	for (const [key, freq] of freqMap) {
		ans.push(freq);
	}

	return ans;
}

groupAnagrams(["eat", "tea", "tan", "ate", "nat", "bat"]);
