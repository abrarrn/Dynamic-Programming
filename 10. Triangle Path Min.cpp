/**Problem link: https://leetcode.com/problems/triangle/ */

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        //tabulation
        int n = triangle.size();
        if(n==1)    return triangle[0][0];
        vector<vector<int>> dp(n, vector<int>(n, -1));

        for(int i=0; i<n; ++i){
            dp[n-1][i] = triangle[n-1][i];
        }
        for(int i=n-2; i>=0; --i){
            for(int j=0; j<=i; ++j){
                dp[i][j] = triangle[i][j] + min(dp[i+1][j], dp[i+1][j+1]);
            }
        }
        return dp[0][0];

        //space-optimized
        vector<int> prev(n, -1);
        vector<int> curr(n, -1);
        for(int i=0; i<n; ++i){
            prev[i] = triangle[n-1][i];
        }
        for(int i=n-2; i>=0; --i){
            for(int j=0; j<=i; ++j){
                curr[j] = triangle[i][j] + min(prev[j], prev[j+1]);
            }
            prev = curr;
        }
        return prev[0];
    }
};
