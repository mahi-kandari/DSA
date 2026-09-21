

class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> d(n, vector<int>(m, INT_MAX));
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;

        d[0][0] = grid[0][0];
        pq.push({grid[0][0], 0, 0});

        vector<int> dr = {-1, 0, 1, 0};
        vector<int> dc = {0, -1, 0, 1};

        while (!pq.empty()) {
            auto top = pq.top();
            pq.pop();
            int cost = top[0];
            int row = top[1];
            int col = top[2];
            if (row == n - 1 && col == m - 1) {
                return cost;
            }
            if (cost > d[row][col]) {
                continue;
            }

            for (int i = 0; i < 4; ++i) {
                int nr = row + dr[i];
                int nc = col + dc[i];

                if (nr >= 0 && nr < n && nc >= 0 && nc < m) {
                    int newCost = cost + grid[nr][nc];
                    if (newCost < d[nr][nc]) {
                        d[nr][nc] = newCost;
                        pq.push({newCost, nr, nc});
                    }
                }
            }
        }

        return d[n - 1][m - 1];
    }
};














