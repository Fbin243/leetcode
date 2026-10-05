class Solution:
    def scoreOfParentheses(self, s: str) -> int:
        score = 0
        depth = 0  # Theo dõi độ sâu hiện tại (số cặp () mở chưa đóng)
        
        for i, char in enumerate(s):
            if char == '(':
                depth += 1
            else:
                depth -= 1
                # Khi gặp ')' và ký tự ngay trước là '(' => đây là cặp "()" cơ bản
                if s[i - 1] == '(':
                    score += 1 << depth  # 1 << depth chính là 2^depth
            
        return score
