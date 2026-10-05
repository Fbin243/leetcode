class Solution:
    def longestValidParentheses(self, s: str) -> int:
        max_len = left = right = 0
        
        # Duyệt từ trái sang phải
        for char in s:
            if char == '(':
                left += 1
            else:
                right += 1
            if left == right:
                max_len = max(max_len, 2 * right)
            elif right > left:  # Nhiều đóng hơn mở => reset
                left = right = 0
                
        # Duyệt từ phải sang trái (để xử lý trường hợp nhiều mở hơn đóng)
        left = right = 0
        for char in reversed(s):
            if char == '(':
                left += 1
            else:
                right += 1
            if left == right:
                max_len = max(max_len, 2 * left)
            elif left > right:  # Nhiều mở hơn đóng => reset
                left = right = 0
                
        return max_len