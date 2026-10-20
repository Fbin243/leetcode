from typing import List

class Solution:
    def sortableIntegers(self, nums: List[int]) -> int:
        n = len(nums)
        sorted_nums = sorted(nums)
        ans = 0
        
        # Step 1: Find all divisors of n
        divs = []
        for i in range(1, int(n**0.5) + 1):
            if n % i == 0:
                divs.append(i)
                if i * i != n:
                    divs.append(n // i)
                    
        # Step 2: Check each divisor
        for k in divs:
            valid = True
            for i in range(0, n, k):
                block = nums[i : i+k]
                target = sorted_nums[i : i+k]
                
                # Count cyclic descents in O(k)
                drops = 0
                drop_idx = -1
                for j in range(k):
                    if block[j] > block[(j + 1) % k]:
                        drops += 1
                        drop_idx = j
                    if drops > 1:
                        valid = False
                        break
                        
                if not valid:
                    break
                    
                if drops == 0:
                    # Already sorted, must exactly match target
                    if block != target:
                        valid = False
                        break
                else:
                    # Exactly 1 descent: rotate to the drop point and compare
                    d = drop_idx
                    if block[d+1:] + block[:d+1] != target:
                        valid = False
                        break
                        
            if valid:
                ans += k
                
        return ans
