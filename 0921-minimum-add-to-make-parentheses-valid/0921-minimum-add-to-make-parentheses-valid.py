class Solution:
    def minAddToMakeValid(self, s: str) -> int:
        open_count = 0  # Số '(' chưa được ghép cặp
        close_count = 0 # Số ')' không thể ghép với '(' trước đó
        
        for char in s:
            if char == '(':
                open_count += 1
            else:
                if open_count > 0:
                    open_count -= 1  # Ghép cặp với '(' chưa đóng
                else:
                    close_count += 1 # ')' dư, cần thêm '(' phía trước
                    
        return open_count + close_count

