class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n=s.size();

        vector<vector<int>> v(n,vector<int>(n));

        for(int i=0;i<n;i++){
            v[i][i]=1;
        }

        for(int l=2;l<=n;l++){
            for(int i=0;i+l-1<n;i++){
                int j=i+l-1;


                if(s[i]==s[j]){
                    v[i][j]=2+v[i+1][j-1];
                }
                else{
                    v[i][j]=max(v[i][j-1],v[i+1][j]);
                }
            }
        }
        return v[0][n-1];




    }
};