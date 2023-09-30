class Solution {
private:
    int recurr(int r, int c, vector<vector<int>>& dp, vector<vector<int>>& grid){
        //base case
        if(r < 0 || c < 0)      return 0;
        if(grid[r][c] == 1)     return 0;
        if(r == 0 && c == 0)    return 1;
        if(dp[r][c] != -1)      return dp[r][c];

        int go_up =  recurr(r-1, c, dp, grid);
        int go_left = recurr(r, c-1, dp, grid);
        return dp[r][c] = go_up + go_left;
    }
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        //memoization
        vector<vector<int>> dp (r, vector<int> (c, -1));
        return recurr(r-1, c-1, dp, obstacleGrid);

        //space-optimized
        vector<int> prev(n, 0);
        for(int i=0; i<m; ++i){
            vector<int> curr(n, 0);
            for(int j=0; j<n; ++j){
                if(obstacleGrid[i][j]==1)   curr[j] = 0;
                else if(i==0 && j==0)       curr[j] = 1;
                else{
                    int up = 0, left = 0;
                    if(i>0) up = prev[j];
                    if(j>0) left = curr[j-1];
                    curr[j] = up + left;
                }
            }
            prev = curr;
        }
        return prev[n-1];
    }
};
