class Solution {
public:
    int dp[501][501];
    int f(string word1,string word2,int i,int j){
        if(i==0 || j==0) return i+j;

        if(dp[i][j]!=-1) return dp[i][j];
        if(word1[i-1]==word2[j-1]) return dp[i][j]= f(word1,word2,i-1,j-1);


        return dp[i][j]=min({1+f(word1,word2,i-1,j-1),1+f(word1,word2,i-1,j),1+f(word1,word2,i,j-1)});

    }
    int minDistance(string word1, string word2) {
        memset(dp,-1,sizeof(dp));

        for(int i=0;i<=word1.size();i++){
            for(int j=0;j<=word2.size();j++){
                if(i==0 || j==0) dp[i][j]=i+j;
                else if(word1[i-1]==word2[j-1]) dp[i][j]=dp[i-1][j-1];
                else{
                    dp[i][j]=min({1+dp[i-1][j],1+dp[i][j-1],1+dp[i-1][j-1]});
                }
            }
        }

        return dp[word1.size()][word2.size()];





        return f(word1,word2,word1.size(),word2.size());
    }
}; 