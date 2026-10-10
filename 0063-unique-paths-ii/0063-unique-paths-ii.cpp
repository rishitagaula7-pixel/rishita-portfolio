class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        
        // If the starting point or destination has an obstacle, no paths exist
        if (obstacleGrid[0][0] == 1 || obstacleGrid[m - 1][n - 1] == 1) {
            return 0;
        }
        
        // Create a DP table initialized to 0
        // Using long long to prevent integer overflow during intermediate additions
        vector<vector<long long>> dp(m, vector<long long>(n, 0));
        
        // Base case: Starting point
        dp[0][0] = 1;
        
        // Fill the first column
        for (int i = 1; i < m; ++i) {
            if (obstacleGrid[i][0] == 0 && dp[i - 1][0] == 1) {
                dp[i][0] = 1;
            }
        }
        
        // Fill the first row
        for (int j = 1; j < n; ++j) {
            if (obstacleGrid[0][j] == 0 && dp[0][j - 1] == 1) {
                dp[0][j] = 1;
            }
        }
        
        // Fill the rest of the DP table
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                if (obstacleGrid[i][j] == 0) {
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
                } else {
                    dp[i][j] = 0; // Obstacle blocks the path
                }
            }
        }
        
        return dp[m - 1][n - 1];
    }
};