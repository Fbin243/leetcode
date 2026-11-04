class Solution:
    def maxPoints(self, points: List[List[int]]) -> int:
        n = len(points)
        if n <= 2:
            return n

        max_count = 0

        for i in range(n):
            slopes = defaultdict(int)
            duplicates = 1  

            for j in range(i + 1, n):
                dx = points[j][0] - points[i][0]
                dy = points[j][1] - points[i][1]

                if dx == 0 and dy == 0:
                    duplicates += 1
                    continue

                g = gcd(dx, dy)
                dx //= g
                dy //= g

                if dx < 0:
                    dx, dy = -dx, -dy
                elif dx == 0 and dy < 0:
                    dy = -dy

                slopes[(dy, dx)] += 1

            current_max = 0
            for count in slopes.values():
                current_max = max(current_max, count)

            max_count = max(max_count, current_max + duplicates)

        return max_count