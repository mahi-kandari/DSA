class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> grid(n, vector<int>(n, INT_MAX));
        for (int i =0;i<n;i++){
            grid[i][i] =0;
        }
        for(auto& edge : edges){
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            grid[u][v] = w;
            grid[v][u] =w;
        }
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (grid[i][k] != INT_MAX && grid[k][j] != INT_MAX) {
                        grid[i][j] = min(grid[i][j], grid[i][k] + grid[k][j]);
                    }
                }
            }
        }
        int city = -1;
        int minCount = n;
        for (int i = 0; i < n; i++) {
            int count = 0;
            for (int j = 0; j < n; j++) {
                if (i != j && grid[i][j] <= distanceThreshold) {
                    count++;
                }
            }
            if (count <= minCount) {
                minCount = count;
                city = i;
            }
        }

        return city;


    }
};