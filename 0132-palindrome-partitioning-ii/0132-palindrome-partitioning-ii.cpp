class Solution {
public:
    int t[2001][2001];
    bool ispali(string s,int i,int j){
        while(i<=j){
            if(s[i]!=s[j]) return false;
            i++;
            j--;
        }

        return true;
    }
    int solve(string& s,int i,int j){
        if(i>=j) return 0;

        if(t[i][j]!=-1) return t[i][j];

        if(ispali(s,i,j)){
            return t[i][j]=0;
        }
        int cuts=INT_MAX;

        for(int k=i;k<=j-1;k++){
            int temp=1+solve(s,i,k) + solve(s,k+1,j);

            cuts=min(cuts,temp);
        }
        return t[i][j]=cuts;
    }
    int minCut(string s) {

        // memset(t,0,sizeof(t));
        int n=s.size();

        vector<vector<bool>> v(n,vector<bool>(n,false));


        for(int i=0;i<n;i++){
            v[i][i]=true;
        }


        for(int l=2;l<=n;l++){
            for(int i=0;i<n-l+1;i++){
                int j=i+l-1;

                if(s[i]==s[j]){
                    if(l==2) v[i][j]=true;
                    else v[i][j]=v[i+1][j-1];
                }
            }
        }

        vector<int> dp(n);


        for(int i=0;i<n;i++){
            if(v[0][i]==true){
                dp[i]=0;
            }
            else{
                dp[i]=INT_MAX;
                for(int k=0;k<i;k++){
                    if(v[k+1][i]==true and 1+dp[k]< dp[i]){
                        dp[i]=1+dp[k];
                    }
                }
            }
        }

        return dp[n-1];







        return solve(s,0,n-1);

    }
};