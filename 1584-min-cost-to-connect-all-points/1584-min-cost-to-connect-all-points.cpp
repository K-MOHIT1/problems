class Solution {
    typedef pair<int,int> p;
public:
    int prims(int& V,vector<vector<p>>& adj){
        priority_queue<p,vector<p>,greater<p>> pq;

        vector<bool> ismst(V,false);

        pq.push({0,0});

        int sum=0;

        while(pq.size()){
            auto curr=pq.top();
            pq.pop();

            int wt=curr.first;
            int node=curr.second;

            if(ismst[node]) continue;

            ismst[node]=true;
            sum += wt;

            for(auto& x:adj[node]){
                int nei=x.first;
                int d=x.second;

                if(!ismst[nei]){
                    pq.push({d,nei});
                }
            }


        }
        return sum;
    }

    int minCostConnectPoints(vector<vector<int>>& points) {
        int V=points.size();
        vector<vector<p>> adj(V);

        for(int i=0;i<V;i++){
            for(int j=i+1;j<V;j++){
                int x1=points[i][0];
                int y1=points[i][1];

                int x2=points[j][0];
                int y2=points[j][1];

                int d=abs(x1-x2)+abs(y1-y2);

                adj[i].push_back({j,d});
                adj[j].push_back({i,d});
            }
        }

        return prims(V,adj);

    }
};