class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> cp = arr;
        unordered_map<int,int> mp;
        sort(cp.begin(),cp.end());
        int a=1;
        for(int i=0;i<cp.size();i++){
            if(i==0) mp[cp[i]]=a;
            else if(cp[i]!=cp[i-1]) mp[cp[i]] = a;
            else{
                continue;
            }
            a++;
        }

        for(int i=0;i<arr.size();i++){
            arr[i]=mp[arr[i]];
        }

        return arr;
        
    }
};