class Solution {
public:
    int recurr(int r, int c, vector<vector<int>>& dp, vector<vector<int>>& grid){
        //base case
        if(r == 0 && c == 0)    return grid[r][c];
        if(r < 0 || c < 0)      return 80000;
        if(dp[r][c] != -1)      return dp[r][c];

        int up = grid[r][c] + recurr(r-1, c, dp, grid);
        int left = grid[r][c] + recurr(r, c-1, dp, grid);
        return dp[r][c] = min(up, left);
    }
    int minPathSum(vector<vector<int>>& grid) {
        //memoization
        int r = grid.size();
        int c = grid[0].size();
        vector<vector<int>> dp(r, vector<int> (c, -1));
        return recurr(r-1, c-1, dp, grid);

        //space-optimized
        int m = grid.size();    //num of rows
        int n = grid[0].size(); //num of cols
        for(int i=1; i<n; ++i){
            grid[0][i] += grid[0][i-1];
        }
        for(int i=1; i<m; ++i){
            grid[i][0] += grid[i-1][0];
        }
        for(int i=1; i<m; ++i){
            for(int j=1; j<n; ++j){
                grid[i][j] += min(grid[i-1][j], grid[i][j-1]);
            }
        }
        return grid[m-1][n-1];
    }
};
