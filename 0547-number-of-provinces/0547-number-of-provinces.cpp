class Solution {
public:
    void dfs(vector<vector<int>>& adj,int x,vector<bool>& v){
        v[x]=true;

        for(int i=0;i<adj[0].size();i++){
            if(!v[i] and adj[x][i]) dfs(adj,i,v);
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n =isConnected.size();
        vector<bool> v(isConnected.size(),false);

        int cnt=0;

        for(int i=0;i<n;i++){
            if(!v[i]){
                dfs(isConnected,i,v);
                cnt++;
            }
        }

        return cnt;


    }
};