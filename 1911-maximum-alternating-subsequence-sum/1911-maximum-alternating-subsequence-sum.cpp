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
        memset(t,-1,sizeof(t));
        return recur(nums,0,1);
    }
};