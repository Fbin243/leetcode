class Solution:
    def removeOuterParentheses(self, s: str) -> str:
        res = []
        depth = 0
        for ch in s:
            if ch == '(':
                depth += 1
                if depth > 1:
                    res.append(ch)
            else:  # ')'
                depth -= 1
                if depth > 0:
                    res.append(ch)
        return ''.join(res)
