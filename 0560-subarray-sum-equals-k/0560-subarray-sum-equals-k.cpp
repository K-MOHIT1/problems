class Solution {
public:

    int subarraySum(vector<int>& nums, int k) {
        vector<int> pre(nums.size(),0);
        pre[0]=nums[0];
       for(int i=1;i<nums.size();i++){
            pre[i]=nums[i]+pre[i-1];
       }
       int ans=0;
       unordered_map<int,int> se;
       for(int i=0;i<pre.size();i++){
            if(pre[i]==k) ans++;
            
            int rem=pre[i]-k;
            if(se.find(rem)!=se.end()){
                ans+=se[rem]; 
            }
            se[pre[i]]++;
       }
       return ans;
    }
};