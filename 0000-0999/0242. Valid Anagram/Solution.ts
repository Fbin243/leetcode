function isAnagram(s: string, t: string): boolean {
	if (s.length != t.length) return false;

	const counter = new Map();
	for (let i = 0; i < s.length; i++) {
		counter.set(s[i], (counter.get(s[i]) || 0) + 1);
		counter.set(t[i], (counter.get(t[i]) || 0) - 1);
	}

	console.log(counter);

	for (const [k, v] of counter) {
		if (v != 0) return false;
	}

	return true;
}
