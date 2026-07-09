class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<int> par(n,0);

        int com=0;

        for(int i=1;i<n;i++){
            if(nums[i]-nums[i-1]>maxDiff) com++;

            par[i]=com;
        }

        vector<bool> ans;

        for(auto x:queries){
            int u=x[0];
            int v=x[1];

            if(par[u]==par[v]) ans.push_back(true);
            else ans.push_back(false);
        }
        return ans;
    }
};