class Solution:
    def removeInvalidParentheses(self, s: str) -> List[str]:
        # --- Đếm số ký tự cần xoá ---
        remove_open, remove_close, balance = 0, 0, 0
        for ch in s:
            if ch == '(':
                balance += 1
            elif ch == ')':
                if balance > 0:
                    balance -= 1
                else:
                    remove_close += 1
        remove_open = balance

        result = []
        seen = set()  # dedup

        def dfs(i, left, cur, ro, rc):
            # Pruning: vượt budget xoá, hoặc balance âm
            if ro < 0 or rc < 0 or left < 0:
                return

            if i == len(s):
                if ro == 0 and rc == 0 and left == 0:
                    if cur not in seen:
                        seen.add(cur)
                        result.append(cur)
                return

            ch = s[i]

            if ch == '(':
                # Option A: xoá
                if ro > 0:
                    dfs(i + 1, left, cur, ro - 1, rc)
                # Option B: giữ
                dfs(i + 1, left + 1, cur + ch, ro, rc)

            elif ch == ')':
                # Option A: xoá
                if rc > 0:
                    dfs(i + 1, left, cur, ro, rc - 1)
                # Option B: giữ (chỉ nếu còn ( để match)
                if left > 0:
                    dfs(i + 1, left - 1, cur + ch, ro, rc)

            else:  # ký tự bình thường → luôn giữ
                dfs(i + 1, left, cur + ch, ro, rc)

        dfs(0, 0, "", remove_open, remove_close)
        return result
