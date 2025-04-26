/**
 * Author: Fbin
 * Link:https://leetcode.com/problems/length-of-last-word/?envType=study-plan-v2&envId=top-interview-150
 * Created at: 26/04/2025
 */

function lengthOfLastWord(s: string): number {
	const n = s.length;
	let start = n - 1;
	for (let i = n - 1; i >= 0; i--) {
		if (s[i] != " ") {
			if (s[i + 1] == " ") {
				start = i;
			}
			if (i == 0 || s[i - 1] == " ") {
				return start - i + 1;
			}
		}
	}

	return -1;
}
