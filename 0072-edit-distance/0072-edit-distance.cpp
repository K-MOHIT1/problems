class Solution {
public:
    int dp[501][501];
    int f(string word1,string word2,int i,int j){
        if(i==word1.size()) return word2.size()-j;
        if(j==word2.size()) return word1.size()-i;

        if(dp[i][j]!=-1) return dp[i][j];
        if(word1[i]==word2[j]) return dp[i][j]= f(word1,word2,i+1,j+1);


        return dp[i][j]=min({1+f(word1,word2,i+1,j+1),1+f(word1,word2,i+1,j),1+f(word1,word2,i,j+1)});

    }
    int minDistance(string word1, string word2) {
        memset(dp,-1,sizeof(dp));

        return f(word1,word2,0,0);
    }
};