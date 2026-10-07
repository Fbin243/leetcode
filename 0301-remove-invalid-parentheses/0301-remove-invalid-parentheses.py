class Solution:
    def removeInvalidParentheses(self, s: str) -> list[str]:
        # Count the minimum number of '(' and ')' that must be removed
        rem_l = rem_r = 0
        for c in s:
            if c == '(':
                rem_l += 1
            elif c == ')':
                if rem_l:
                    rem_l -= 1
                else:
                    rem_r += 1

        n = len(s)
        res = set()

        def dfs(i: int, l: int, r: int, open_: int, path: list[str]) -> None:
            if l + r > n - i:          # not enough chars left to remove
                return
            if i == n:
                if l == 0 and r == 0 and open_ == 0:
                    res.add("".join(path))
                return

            c = s[i]
            if c == '(':
                if l > 0:                              # remove it
                    dfs(i + 1, l - 1, r, open_, path)
                path.append(c)                         # keep it
                dfs(i + 1, l, r, open_ + 1, path)
                path.pop()
            elif c == ')':
                if r > 0:                              # remove it
                    dfs(i + 1, l, r - 1, open_, path)
                if open_ > 0:                          # keep it only if it matches
                    path.append(c)
                    dfs(i + 1, l, r, open_ - 1, path)
                    path.pop()
            else:                                      # letters are always kept
                path.append(c)
                dfs(i + 1, l, r, open_, path)
                path.pop()

        dfs(0, rem_l, rem_r, 0, [])
        return list(res)