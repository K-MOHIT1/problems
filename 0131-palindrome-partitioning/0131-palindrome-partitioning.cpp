class Solution {
public:
    void solve(vector<vector<string>>& result,vector<string>&temp,string& s,int i,vector<vector<bool>>& v){
        if(i==s.size()){
            result.push_back(temp);
            return;
        }

        for(int j=i;j<s.size();j++){
            if(v[i][j]==true){
                temp.push_back(s.substr(i,j-i+1));
                solve(result,temp,s,j+1,v);
                temp.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        int n=s.size();
        vector<vector<bool>> v(n,vector<bool>(n,0));
        
        for(int i=0;i<n;i++){
            v[i][i]=true;
        }

        for(int l=2;l<=n;l++){
            for(int i=0;i<n-l+1;i++){

                int j=i+l-1;
                if(s[i]==s[j]){
                    if(l==2) v[i][j]=true;
                    else{
                        v[i][j]=v[i+1][j-1];
                    }
                }
                else v[i][j]=false;

            }
        } 

        vector<vector<string>> result;
        vector<string> temp;
        solve(result,temp,s,0,v);

        return result;
    }
};