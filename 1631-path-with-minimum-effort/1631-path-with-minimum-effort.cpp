class Solution {
public:
    typedef pair<int,pair<int,int>> p;
    vector<vector<int>> directions={{1,0},{0,1},{0,-1},{-1,0}};
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m=heights.size();
        int n=heights[0].size();
        priority_queue<p,vector<p>,greater<p>> pq;

        vector<vector<int>> result(m,vector<int>(n,INT_MAX));

        auto issafe = [&](int x,int y){
            if(x>=0 and y>=0 and x<m and y<n) return true;
            else return false;
        };

        result[0][0]=0;
        pq.push({0,{0,0}});

        while(pq.size()){
            int d=pq.top().first;
            auto curr=pq.top().second;
            pq.pop();

            int x=curr.first;
            int y=curr.second;

            for(auto dir:directions){
                int x_=x+dir[0];
                int y_=y+dir[1];

                if(issafe(x_,y_)){
                    int currdiff = abs(heights[x][y]-heights[x_][y_]);
                    int maxd = max(currdiff,d);

                    if(result[x_][y_] > maxd){
                        result[x_][y_]=maxd;
                        pq.push({maxd,{x_,y_}});
                    }
                }
            }


        }

        return result[m-1][n-1];


    }
};