class Solution:
    def maxDepthAfterSplit(self, s: str) -> List[int]:
        res = []
        d0, d1 = 0, 0  # depth hiện tại của group 0 và 1

        for ch in s:
            if ch == '(':
                if d0 <= d1:
                    res.append(0)
                    d0 += 1
                else:
                    res.append(1)
                    d1 += 1
            else:  # ')'
                if d0 > d1:
                    res.append(0)
                    d0 -= 1
                else:
                    res.append(1)
                    d1 -= 1

        return res
