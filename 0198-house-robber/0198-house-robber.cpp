class Solution {
public:
    vector<int> dp;
    int recur(vector<int>& nums,int i,int val){
        if(i>=nums.size()){
            return 0;
        }
        if(dp[i]!=-1) return dp[i];

        int ans=max(recur(nums,i+1,val),nums[i] + recur(nums,i+2,val));

        return dp[i]=ans;
    }
    int rob(vector<int>& nums) {
        dp.resize(401,-1);
        return recur(nums,0,0);
    }
};