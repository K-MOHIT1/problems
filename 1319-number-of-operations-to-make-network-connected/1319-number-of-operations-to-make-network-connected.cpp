class Solution {
public:

    vector<int> parent;
    vector<int> rank;

    int find(int x){
        if(x==parent[x]) return x;

        return parent[x]=find(parent[x]);

    }


    void Union(int x,int y){
        int px=parent[x];
        int py=parent[y];

        if (px == py)
            return;

        if (rank[px] < rank[py]) {
            parent[px] = py;
        }
        else if (rank[px] > rank[py]) {
            parent[py] = px;
        }
        else {
            parent[py] = px;
            rank[px]++;
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size()<n-1) return -1;
        parent.resize(n);
        rank.resize(n,0);

        for(int i=0;i<n;i++){
            parent[i]=i;
        }
        int ans=n;


        for(int i=0;i<connections.size();i++){
            int x=connections[i][0];
            int y=connections[i][1];

            if(find(x)!=find(y)){
                Union(x,y);
                ans--;
            }
        }

        return ans-1;
    }
};