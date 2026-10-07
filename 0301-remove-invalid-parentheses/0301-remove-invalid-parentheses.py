class Solution:
    def removeInvalidParentheses(self, s: str) -> List[str]:
        n = len(s)
        
        # --- Đếm số cần xoá ---
        ro, rc, bal = 0, 0, 0
        for ch in s:
            if ch == '(':
                bal += 1
            elif ch == ')':
                if bal > 0:
                    bal -= 1
                else:
                    rc += 1
        ro = bal

        # --- Trick 1: Suffix counts ---
        suf_o = [0] * (n + 1)   # số '(' từ i đến cuối
        suf_c = [0] * (n + 1)   # số ')' từ i đến cuối
        for i in range(n - 1, -1, -1):
            suf_o[i] = suf_o[i + 1] + (s[i] == '(')
            suf_c[i] = suf_c[i + 1] + (s[i] == ')')

        result, seen, fail = [], set(), set()

        def dfs(i, left, cur, ro, rc):
            # Pruning cơ bản
            if ro < 0 or rc < 0 or left < 0:
                return
            # --- Trick 1: suffix prune ---
            if ro > suf_o[i] or rc > suf_c[i]:
                return
            # --- Trick 2: fail memo ---
            state = (i, left, ro, rc)
            if state in fail:
                return

            if i == n:
                if ro == 0 and rc == 0 and left == 0:
                    if cur not in seen:
                        seen.add(cur)
                        result.append(cur)
                return

            ch = s[i]

            if ch == '(':
                # Xoá
                if ro > 0:
                    dfs(i + 1, left, cur, ro - 1, rc)
                    # --- Trick 3: skip consecutive ---
                    j = i + 1
                    while j < n and s[j] == '(':
                        j += 1
                    # Branch "giữ" chỉ chạy 1 lần (không lặp cho '(':
                    if j != i + 1:
                        dfs(i + 1, left + 1, cur + '(', ro, rc)
                    else:
                        dfs(i + 1, left + 1, cur + '(', ro, rc)
                        # (giữ rồi tiếp tục, bình thường)
                else:
                    dfs(i + 1, left + 1, cur + '(', ro, rc)

            elif ch == ')':
                # Xoá
                if rc > 0:
                    dfs(i + 1, left, cur, ro, rc - 1)
                    j = i + 1
                    while j < n and s[j] == ')':
                        j += 1
                # Giữ
                if left > 0:
                    dfs(i + 1, left - 1, cur + ')', ro, rc)

            else:
                dfs(i + 1, left, cur + ch, ro, rc)

            # Ghi nhớ dead state (nếu cả 2 branch đều fail)
            # → thực ra ghi ở đầu function đã đủ, không cần ở đây

        dfs(0, 0, "", ro, rc)
        return result
