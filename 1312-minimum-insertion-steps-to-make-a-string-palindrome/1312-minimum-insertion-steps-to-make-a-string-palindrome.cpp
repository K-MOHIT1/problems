class Solution {
public:
    int dp[502][502];
    int f(string s,int i,int j){
        if(i>=j){
            return 0;
        }

        if(dp[i][j]!=-1) return dp[i][j];

        if(s[i]==s[j]) return dp[i][j]=f(s,i+1,j-1);
 
        return dp[i][j]=min(1+f(s,i+1,j),1+f(s,i,j-1));
    }
    int minInsertions(string s) {
        memset(dp,0,sizeof(dp));
        int n=s.size();

         for(int i=0;i<n;i++){
            dp[i][i]=0;

         }


         for(int l=2;l<=n;l++){
            for(int i=0;i<n-l+1;i++){
                int j=i+l-1;

                if(s[i]==s[j]) dp[i][j]=dp[i+1][j-1];
                else dp[i][j]=min(1+dp[i+1][j],1+dp[i][j-1]);
            }
         }

         return dp[0][n-1];


        return f(s,0,s.size()-1);
    }
};