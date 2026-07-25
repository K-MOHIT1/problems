class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        // return solve(str1,str2,st1.size(),str2.size());
        int m=str1.size();
        int n=str2.size();

        vector<vector<int>> t(m+1,vector<int>(n+1));
        string a="";

        for(int i=0;i<m+1;i++){
            for(int j=0;j<n+1;j++){
                if(i==0 || j==0){
                    t[i][j]=i+j;
                }
                else if(str1[i-1]==str2[j-1]){
                    t[i][j]=1+t[i-1][j-1];
                }
                else{
                    t[i][j]=1+ min(t[i-1][j],t[i][j-1]);
                }
            }
        }

        while(m>0 and n>0){
            if(str1[m-1]==str2[n-1]){
                a+=(str1[m-1]);
                m--;
                n--;

            }
            else if(t[m-1][n] < t[m][n-1]){
                a+=str1[m-1];
                m--;
            }
            else{
                a+=str2[n-1];
                n--;
            }
        }

        while(m>0){
            a+=str1[m-1];
            m--;
        }

        while(n>0){
            a+=str2[n-1];
            n--;
        }

        reverse(a.begin(),a.end());

        return a;



    }
};