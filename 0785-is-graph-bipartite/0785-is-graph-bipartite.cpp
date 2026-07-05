class Solution {
public:

    bool dfs(vector<vector<int>>& adj,int i,vector<int>& color,int curr){
        color[i]=curr;

        for(int x:adj[i]){
            if(color[i]==color[x]) return false;
            else if(color[x]==-1){
                if(!dfs(adj,x,color,!color[i])) return false;
            }
        }
        return true;

    }

    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> color(graph.size(),-1);

        for(int i=0;i<graph.size();i++){
            if(color[i]==-1){
                if(!dfs(graph,i,color,0)) return false;;
            }
        }
        return true;
    }
};