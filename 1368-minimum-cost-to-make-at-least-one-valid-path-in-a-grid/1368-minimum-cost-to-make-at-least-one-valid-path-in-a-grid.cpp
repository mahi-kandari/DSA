
using namespace std;

class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        // Distance/cost array initialized with infinity
        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
        deque<pair<int, int>> dq;
        
        // Directions corresponding to signs:
        // 1: Right (0, 1), 2: Left (0, -1), 3: Down (1, 0), 4: Up (-1, 0)
        int dx[] = {0, 0, 1, -1};
        int dy[] = {1, -1, 0, 0};
        
        // Start at (0, 0) with cost 0
        dist[0][0] = 0;
        dq.push_back({0, 0});
        
        while (!dq.empty()) {
            auto [x, y] = dq.front();
            dq.pop_front();
            
            // If we reached the bottom-right corner, return the cost
            if (x == n - 1 && y == m - 1) {
                return dist[x][y];
            }
            
            for (int i = 0; i < 4; ++i) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                
                // Check bounds
                if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
                    // Edge weight is 0 if moving in the direction of the sign (i + 1), else 1
                    int weight = (grid[x][y] == i + 1) ? 0 : 1;
                    
                    if (dist[x][y] + weight < dist[nx][ny]) {
                        dist[nx][ny] = dist[x][y] + weight;
                        
                        // Push 0-weight edges to the front, 1-weight edges to the back
                        if (weight == 0) {
                            dq.push_front({nx, ny});
                        } else {
                            dq.push_back({nx, ny});
                        }
                    }
                }
            }
        }
        
        return dist[n - 1][m - 1];
    }
};