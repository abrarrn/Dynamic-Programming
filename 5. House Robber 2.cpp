/*The houses are in circle and can not rob from consecutive houses*/
class Solution {
private:
    int max_profit(int b, int e, vector<int>& nums){
        int prev2 = nums[b];
        int prev1 = max(nums[b], nums[b+1]);
        int res = 0;
        for(int i=b+2; i<=e; ++i){
            res = max(nums[i] + prev2, prev1);
            prev2 = prev1;
            prev1 = res;
        }
        return res;
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1)  return nums[0];
        if(n == 2)  return max(nums[0], nums[1]);
        if(n == 3)  return max(max(nums[0], nums[1]), nums[2]);
        return max(max_profit(0, n-2, nums), max_profit(1, n-1, nums));
    }
};
