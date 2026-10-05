class Solution:
    def longestValidParentheses(self, s: str) -> int:
        stack = [-1]  # Mốc cơ sở ban đầu (chỉ số -1 giúp tính đúng độ dài từ đầu chuỗi)
        max_len = 0
        
        for i, char in enumerate(s):
            if char == '(':
                stack.append(i)  # Đẩy chỉ số của '(' vào stack
            else:
                stack.pop()  # Gặp ')' -> pop ra 1 '(' (xử lý 1 cặp hợp lệ)
                if not stack:
                    stack.append(i)  # Stack rỗng => cập nhật mốc cơ sở mới cho chuỗi tiếp theo
                else:
                    # Độ dài chuỗi hợp lệ hiện tại = chỉ số hiện tại - chỉ số trên đỉnh stack
                    max_len = max(max_len, i - stack[-1])
                    
        return max_len
