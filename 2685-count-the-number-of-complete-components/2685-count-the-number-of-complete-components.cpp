class Solution {
public:
    vector<int> parent;
    vector<int> rank;

    int find(int x){
        if(x==parent[x]) return x;

        return parent[x]=find(parent[x]);
    }

    void Union(int x,int y){
        int xp=find(x);
        int yp=find(y);

        if(xp == yp) return;

        if(rank[xp]>rank[yp]) parent[yp]=xp;
        else if(rank[xp]<rank[yp]) parent[xp]=yp;
        else{
            parent[yp]=xp;
            rank[xp]++;
        }

    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        parent.resize(n);
        rank.resize(n,0);

        for(int i=0;i<n;i++) parent[i]=i;
        
        for(auto &edge:edges){
            Union(edge[0], edge[1]);
        }

        unordered_map<int,int> mpe;

        for(auto &edge:edges){
            mpe[find(edge[0])]++;
        }

        unordered_map<int,int>  mpv;

        for(int i=0;i<n;i++){
            mpv[find(parent[i])]++;
        }

        int ans=0;


        for(auto x:mpv){
            int ver=x.second;

            int edg=0;

            if(mpe.find(x.first)!=mpe.end()){
                edg=mpe[x.first];
            }

            if(edg==(ver*(ver-1)/2)) ans++;
        }

        return ans;



    }
};