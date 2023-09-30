int dp[100001][4];

int helper(int day, int task_done, vector<vector<int>> &points, vector<vector<int>> &dp){
    //base case
    if(day == 0){
        int max_points = 0;
        for(int i=0; i<3; ++i){
            if(i != task_done){
                max_points = max(max_points, points[day][i]);
            }
        }
        return max_points;
    }

    if(dp[day][task_done] != -1)    return dp[day][task_done];

    int max_points = 0;
    for(int i=0; i<3; ++i){
        if(i != task_done){
            max_points = max(max_points, points[day][i] + helper(day-1, i, points, dp));
        }
    }
    return dp[day][task_done] = max_points;
}
int ninjaTraining(int n, vector<vector<int>> &points)
{
    //memoization
    vector<vector<int>> dp(n, vector<int>(4, -1));
    return helper(n-1, 3, points, dp);

    //tabulation
    vector<vector<int>> dp(n, vector<int>(3, -1));
    dp[0][0] = max(points[0][1], points[0][2]);
    dp[0][1] = max(points[0][0], points[0][2]);
    dp[0][2] = max(points[0][0], points[0][1]);
    /*dp[0][*] represents- on the 0th day, task * was not done and the maximum to get from this day...
    dp[1..][*] represents- on the specific day task 1.. is done and the maximum is...*/
    for(int i=1; i<n; ++i){         //for each day
        for(int j=0; j<3; ++j){     //for each task
            for(int k=0; k<3; ++k){ //for each task again
                if(j != k){
                    dp[i][j] = max(dp[i][j], points[i][k] + dp[i-1][k]);
                }
            }
        }
    }
    int res = 0;
    for(int i=0; i<3; ++i){
        res = max(res, dp[n-1][i]);
    }
    return res;
}
