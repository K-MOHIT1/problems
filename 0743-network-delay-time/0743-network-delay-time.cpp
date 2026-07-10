class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int> par(n+1,INT_MAX);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;

        par[k]=0;
        pq.push({0,k});

        vector<vector<pair<int,int>>> adj(n+1);

        for(auto x:times){
            int u=x[0];
            int v=x[1];
            int wt=x[2];

            adj[u].push_back({v,wt});
        }

        while(pq.size()){
            int d=pq.top().first;
            int node=pq.top().second;
            pq.pop();

            if(d>par[node]) continue;


            for(auto x:adj[node]){
                int nei=x.first;
                int wt=x.second;

                if(d+wt<par[nei]){
                    par[nei]=d+wt;
                    pq.push({d+wt,nei});
                }
            }
        }

        int ans=0;

        for(int i=1;i<par.size();i++){
            ans=max(ans,par[i]);
        }

        if(ans==INT_MAX) return -1;
        return ans;

    }
};