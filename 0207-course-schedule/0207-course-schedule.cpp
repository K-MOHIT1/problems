class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n=numCourses;
        vector<vector<int>> adj(n);
        vector<int> ind(n,0);

        for(int i=0;i<prerequisites.size();i++){
            int a=prerequisites[i][0];
            int b=prerequisites[i][1];

            adj[b].push_back(a);
            ind[a]++;
        }


        queue<int> q;

        for(int i=0;i<n;i++){
            if(ind[i]==0) q.push(i);
        }

        vector<int> ans;

        while(q.size()){
            int x=q.front();
            q.pop();
            ans.push_back(x);

            for(int u:adj[x]){
                ind[u]--;

                if(ind[u]==0) q.push(u);
            }
        }

        if(ans.size()==n) return true;
        return false;
    }
    
};