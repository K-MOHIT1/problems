class Solution {
public:

int t[1001][1001];

bool ispred(string& prev,string& curr){
    int m=prev.size();
    int n=curr.size();


    if(m>=n || n-m!=1) return false;

    int i=0,j=0;

    while(i<m and j<n){
        if(prev[i]==curr[j]) i++;

        j++;
    }

    return i==m;
}

    int lis(vector<string>& words,int prev,int curr){
        if(curr==words.size()) return 0;

        if(prev!=-1 and t[prev][curr]!=-1) return t[prev][curr];

        int take=0,skip=0;

        if(prev==-1 || ispred(words[prev],words[curr])){
            take=1+lis(words,curr,curr+1);
        }

        skip=lis(words,prev,curr+1);

        if(prev!=-1){
            t[prev][curr]=max(take,skip);
        }

        return max(take,skip);
    }
    int longestStrChain(vector<string>& words) {

        memset(t,-1,sizeof(t));
        int n=words.size();
        sort(words.begin(),words.end(),[](string a,string b){
            return a.size()<b.size();
        });

        //bottom up
        vector<int> t(n,1);
        int maxl=1;

        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                
                if(ispred(words[j],words[i])){
                    t[i]=max(t[j]+1,t[i]);
                    maxl=max(maxl,t[i]);
                }
            }
        }

        return maxl;



        return lis(words,-1,0);
    }
};