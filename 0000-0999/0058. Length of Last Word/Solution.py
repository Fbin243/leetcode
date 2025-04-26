'''
/**
 * Author: Fbin
 * Link:https://leetcode.com/problems/length-of-last-word/?envType=study-plan-v2&envId=top-interview-150
 * Created at: 26/04/2025
 */
'''

class Solution:
	def lengthOfLastWord(self, s: str) -> int:
		n = len(s)
		i = n - 1
		while s[i] == " ":
			i -= 1
		j = i
		while s[j] != " " and j >= 0:
			j -= 1
		return i - j
