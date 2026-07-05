class Solution {
public:

    bool dfs(vector<vector<int>>& adj,int i,vector<int>& color,int curr){
        queue<int> q;
        color[i]=curr;
        q.push(i);

        while(q.size()){
            int u=q.front();
            q.pop();

            for(int x:adj[u]){
                if(color[x]==color[u]) return false;

                if(color[x]==-1){
                    color[x]=!color[u];
                    q.push(x);
                }
            }
        }
        return true;

    }

    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> color(graph.size(),-1);

        for(int i=0;i<graph.size();i++){
            if(color[i]==-1){
                if(!dfs(graph,i,color,0)) return false;
            }
        }
        return true;
    }
};