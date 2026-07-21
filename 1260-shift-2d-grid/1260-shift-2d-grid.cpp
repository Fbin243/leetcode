class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        k = k % (m*n);
        if(k == 0) return grid;
        queue<int> s;
        int x, y;
        int i = m*n - 1;
        for(; i > k - 1; i--) {
            x = i/n;
            y = i%n;
            if(i >= m*n - k) s.push(grid[x][y]);
            grid[x][y] = grid[(i-k)/n][(i-k)%n];
        }   
        while(i >= m*n-k) {
            s.push(grid[i/n][i%n]);
            i--;
        }
        i = k -1;
        while(i >= 0 && !s.empty()) {
            grid[i/n][i%n] = s.front();
            s.pop();
            i--;
        }
        return grid;
    }
};