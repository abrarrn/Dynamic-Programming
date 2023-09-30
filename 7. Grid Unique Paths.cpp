class Solution {
public:
    int recurr(int r, int c, vector<vector<int>>&dp){
        //base case
        if(r == 0 && c == 0)    return 1;
        if(r < 0 || c < 0)      return 0;
        if(dp[r][c] != -1)      return dp[r][c];

        int up = recurr(r-1, c, dp);
        int left = recurr(r, c-1, dp);
        return dp[r][c] = up + left;
    }
    int uniquePaths(int m, int n) {
        //memoization
        vector<vector<int>> dp(m, vector<int>(n,-1));
        return recurr(m-1, n-1, dp);

        //tabulation
        int dp[m][n];
        memset(dp, 0, sizeof(dp));
        for(int i=0; i<m; ++i){
            for(int j=0; j<n; ++j){
                if(i==0 || j==0)    dp[i][j] = 1;
                if(i>0 && j>0)      dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        return dp[m-1][n-1];

        //space-optimized
        vector<int> prev(n, 0);
        vector<int> curr(n, 0);
        for(int i=0; i<m; ++i){
            for(int j=0; j<n; ++j){
                if(i==0 || j==0)    curr[j] = 1;
                if(i>0 && j>0)      curr[j] = prev[j] + curr[j-1];
            }
            prev = curr;
        }
        return curr[n-1];
    }
};
