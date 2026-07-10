class Solution {
public:
//bfs
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {



        vector<vector<int>> dir={{1,1},{0,1},{1,0},{0,-1},{-1,0},{-1,-1},{-1,1},{1,-1}};
        int m=grid.size();
        int n=grid[0].size();

        if (grid[0][0] != 0 || grid[m - 1][n - 1] != 0) 
            return -1;


        queue<pair<int,int>> q;
        q.push({0,0});
        grid[0][0]=1;
        int level=1;

        auto issafe = [&](int x,int y){
            if(x>=0 and x<m and y>=0 and y<n) return true;
            return false;
        };

        while(q.size()){

            int N=q.size();

            
            while(N--){
                auto curr=q.front();
                q.pop();


                int x=curr.first;
                int y=curr.second;

                if(x==m-1 and y==n-1) return level;

                for(auto& di:dir){
                    int x_=x+ di[0];
                    int y_=y+di[1];

                    if(issafe(x_,y_) and grid[x_][y_]==0){
                        grid[x_][y_]=1;
                        q.push({x_,y_});
                    }
                }
            }

            level++;

        }

        return -1;


    }
};