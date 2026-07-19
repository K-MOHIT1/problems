class Solution {
public:
    vector<int> dp;
    int recur(vector<int>& nums,int i,int n){
        if(i>n){
            return 0;
        }
        if(dp[i]!=-1) return dp[i];

        int ans=max(recur(nums,i+1,n),nums[i] + recur(nums,i+2,n));

        return dp[i]=ans;
    }
    int rob(vector<int>& nums) {
        dp.resize(401,-1);

        int n=nums.size();

        if(n==1) return nums[0];

        if(n==2) return max(nums[0],nums[1]);

        // dp[0]=0;
        // dp[1]=nums[0];

        // for(int i=2;i<=nums.size();i++){
        //     dp[i]=max(dp[i-1],nums[i-1]+dp[i-2]);
        // }

        // return dp[nums.size()];

        int h1=recur(nums,0,n-2);

        dp.clear();
        dp.resize(401,-1);

        int h2=recur(nums,1,n-1);


        
        return max(h1,h2);
    }
};