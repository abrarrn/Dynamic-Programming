class Solution {
private:
    int recurr(vector<int>& nums, int i, vector<int>& dp){
        if(i == 0)      return nums[i];
        if(i < 0)       return 0;
        if(dp[i] != -1) return dp[i];
        int pick = nums[i] + recurr(nums, i - 2, dp);
        int notPick = recurr(nums, i - 1, dp);
        return dp[i] = max(pick, notPick);
    }
public:
    int rob(vector<int>& nums) {
        //memoization
        //vector<int> dp(100, -1);
        //return recurr(nums, nums.size()-1, dp);

        //tabulation
        if(nums.size()==1)  return nums[0];
        if(nums.size()==2)  return max(nums[0], nums[1]);
        vector<int> dp(100, -1);
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        for(int i = 2; i < nums.size(); ++i){
            dp[i] = max(nums[i] + dp[i - 2], dp[i - 1]);
        }
        return dp[nums.size()-1];
    }
};
