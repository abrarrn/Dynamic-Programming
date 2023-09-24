#include <bits/stdc++.h>
int dp[1001];

int recurr(int n, vector<int> &heights){
    if(n == 0)      return 0;
    if(dp[n] != -1) return dp[n];
    int step1 = recurr(n-1, heights) + abs(heights[n]-heights[n-1]);
    int step2 = INT_MAX;
    if(n > 1)
        step2 = recurr(n-2, heights) + abs(heights[n]-heights[n-2]);
    return dp[n] = min(step1, step2);
}

int frogJump(int n, vector<int> &heights)
{
    //memoization
    vector<int> dp(n, 0);
    return recurr(n-1, heights);

    //tabulation
    vector<int> dp(n, 0);
    dp[0] = 0;
    for(int i=1; i<=n-1; ++i){
        int step1 = dp[i-1] + abs(heights[i]-heights[i-1]);
        int step2 = INT_MAX;
        if(i > 1)
            step2 = dp[i-2] + abs(heights[i]-heights[i-2]);
        dp[i] = min(step1, step2);
    }
    return dp[n-1];
    
    //space-optimized
    int prev1 = 0;
    int prev2 = 0;
    int res = INT_MAX;
    for(int i=1; i<=n-1; ++i){
        int step1 = prev1 + abs(heights[i]-heights[i-1]);
        int step2 = INT_MAX;
        if(i > 1)
            step2 = prev2 + abs(heights[i]-heights[i-2]);
        res = min(step1, step2);
        prev2 = prev1;
        prev1 = res;
    }
    return res;
}
