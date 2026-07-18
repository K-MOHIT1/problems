class Solution {
public:
    void go(vector<int>&a,int idx,vector<int>&temp, vector<vector<int>>&ans){
        ans.push_back(temp);
            
        for(int i=idx;i< a.size();i++){
            //pick 
            if(i!=idx && a[i]==a[i-1])continue;
            temp.push_back(a[i]);
            go(a,i+1,temp,ans);
            temp.pop_back();

        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>temp;
        sort(nums.begin(),nums.end());

        go(nums,0,temp,ans);

        return ans;
    }
};