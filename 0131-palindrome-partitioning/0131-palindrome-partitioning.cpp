class Solution {
public:

    bool ispali(string s,int start,int end){
        while(start<end){
            if(s[start]!=s[end]) return false;
            start++;
            end--;
        }
        return true;
    }

    void recur(int idx,string s,vector<vector<string>>& ans,vector<string> temp){
        if(idx==s.length()){
            ans.push_back(temp);
            return;
        }

        for(int i=idx;i<s.size();i++){
            if(ispali(s,idx,i)){
                temp.push_back(s.substr(idx,i-idx+1));
                recur(i+1,s,ans,temp);
                temp.pop_back();

            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> temp;
        recur(0,s,ans,temp);
        return ans;
    }
};