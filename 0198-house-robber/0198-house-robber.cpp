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
        dp.resize(401,0);

        dp[0]=0;
        dp[1]=nums[0];

        for(int i=2;i<=nums.size();i++){
            dp[i]=max(dp[i-1],nums[i-1]+dp[i-2]);
        }

        return dp[nums.size()];



        
        return recur(nums,0,0);
    }
};