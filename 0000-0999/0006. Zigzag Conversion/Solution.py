class Solution:
	def convert(self, s: str, numRows: int) -> str:
		if numRows == 1 or numRows > len(s): return s
		rows = ["" for _ in range(numRows)]
		idx = 0
		for char in s:
			rows[idx] += char
			if idx == 0:
				d = 1
			elif idx == numRows - 1:
				d = -1
			idx += d

		return "".join(rows)
