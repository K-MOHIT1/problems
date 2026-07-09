class Solution {
public:
    int find(int x,vector<int>& parent){
        if(x==parent[x]) return x;

        return parent[x]=find(parent[x],parent);
    }

    void Union(int x,int y,vector<int>& par){

        int px=find(x,par);
        int py=find(y,par);

        if(px==py) return;

        par[py]=px;

    }
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<int> par(n);

        for(int i=0;i<n;i++){
            par[i]  =  i;
        }

        for(int i=1;i<nums.size();i++){
            int x=nums[i-1];
            int y=nums[i];

            if(abs(x-y)<=maxDiff){
                Union(i-1,i,par);
            }
        }


        vector<bool> ans(queries.size());

        for(int i=0;i<queries.size();i++){
            ans[i]=(find(queries[i][0],par)==find(queries[i][1],par));
        }

        return ans;



    }
};