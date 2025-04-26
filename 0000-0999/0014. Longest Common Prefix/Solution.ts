function longestCommonPrefix(strs: string[]): string {
	let res = "";
	strs.sort();
	const first = strs[0];
	const last = strs[strs.length - 1];
	for (let i = 0; i < Math.min(first.length, last.length); i++) {
		if (first[i] != last[i]) break;
		res += first[i];
	}

	return res;
}
