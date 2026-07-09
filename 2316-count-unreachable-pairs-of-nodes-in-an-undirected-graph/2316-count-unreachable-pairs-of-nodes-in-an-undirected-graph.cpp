class Solution {
public:

    void dfs(vector<vector<long long>>& adj,int i,vector<bool>& vis,long long& len){
        len=len+1;
        vis[i]=true;

        for(int x:adj[i]){
            if(!vis[x]) dfs(adj,x,vis,len);
        }

    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        int sz=n;

        vector<bool> vis(n,false);

        vector<vector<long long>> adj(n);

        for(auto &e : edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        long long ans=0;

        for(int i=0;i<n;i++){
            long long temp=0;

            if(!vis[i]){
                dfs(adj,i,vis,temp);
                ans+=(temp)*(sz-temp);
                sz=sz-temp;
            }


        }

        return ans;


    }
};