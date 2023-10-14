class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int dp[n][m][m];
        memset(dp, 0, sizeof(dp));

        //handling base case
        for(int j1=0; j1<m; j1++)
            for(int j2=0; j2<m; j2++)
                if(j1 == j2)
                    dp[n-1][j1][j2] = grid[n-1][j1];
                else
                    dp[n-1][j1][j2] = grid[n-1][j1] + grid[n-1][j2];

        for (int i=n-2; i>=0; i--) {
            for (int j1=0; j1<m; j1++) {
                for (int j2=0; j2<m; j2++) {
                    int maxi = 1e-8;
                    //trying out the 9 combinations
                    for (int dj1=-1; dj1<=1; dj1++) {
                        for (int dj2=-1; dj2<=1; dj2++) {
                            int curr;
                            //getting the prev
                            if ((j1 + dj1 < 0 || j1 + dj1 >= m) || (j2 + dj2 < 0 || j2 + dj2 >= m))
                                curr = 1e-8;
                            else
                                curr = dp[i+1][j1+dj1][j2+dj2];

                            //getting the current
                            if (j1 == j2)
                                curr += grid[i][j1];
                            else
                                curr += grid[i][j1] + grid[i][j2];
                            maxi = max(curr, maxi);
                        }
                    }
                    dp[i][j1][j2] = maxi;
                }
            }
        }
        return dp[0][0][m-1];
    }
};
