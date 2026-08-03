class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.size();

        vector<vector<bool>> v(n,vector<bool>(n,false));
        int idx=0;
        int len=1;



        for(int l=1 ;l<=n;l++){
            for(int i=0;i+l-1<n;i++){
                int j=i+l-1;

                if(i==j) v[i][j]=true;
                else if(i+1==j and (s[i]==s[j])){
                    v[i][j]= true;
                    len=2;
                    idx=i;
                }
                else if((s[i]==s[j] && v[i+1][j-1])){
                    v[i][j]= true;
                    if(j-i+1>len){
                        len=j-i+1;
                        idx=i;
                    }

                }
                else v[i][j]=false;

                
            }
        }

        return s.substr(idx,len);
        
    }
};