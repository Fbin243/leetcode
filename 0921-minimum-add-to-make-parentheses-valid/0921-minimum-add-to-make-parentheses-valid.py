class Solution:
    def minAddToMakeValid(self, s: str) -> int:
        open_count = 0   # số "(" chưa được match
        added = 0        # số ")" thừa (cần thêm "(" trước đó)
        
        for ch in s:
            if ch == '(':
                open_count += 1
            else:  # ch == ')'
                if open_count > 0:
                    open_count -= 1   # match với 1 "(" trước đó
                else:
                    added += 1        # không có "(" để match → cần thêm 1 "("
        
        # open_count: số "(" thừa → cần thêm ")"
        # added: số ")" thừa → cần thêm "("
        return open_count + added
