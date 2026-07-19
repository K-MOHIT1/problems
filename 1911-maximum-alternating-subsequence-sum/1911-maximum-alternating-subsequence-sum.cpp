class Solution {
public:
    typedef long long ll;
    ll t[1000001][2];

    ll recur(vector<int>& nums,ll i,bool sig){
        if(i>=nums.size()) return 0;

        if(t[i][sig]!=-1) return t[i][sig];

        ll skip=recur(nums,i+1,sig);
        ll take=(sig?1:-1)*nums[i]+recur(nums,i+1,!sig);

        return t[i][sig]=max(skip,take);
    }
    long long maxAlternatingSum(vector<int>& nums) {
        int n=nums.size();
        memset(t,0,sizeof(t));  //-1 for rec



        //bottom up
        for(int i=1;i<n+1;i++){
            t[i][0]= max(t[i-1][1]-nums[i-1],t[i-1][0]);
            t[i][1]= max(t[i-1][0]+nums[i-1],t[i-1][1]);
        }

        return max(t[n][0],t[n][1]);



        return recur(nums,0,1);
    }
};