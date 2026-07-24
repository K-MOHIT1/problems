class Solution {
public: 
    void solve(vector<int>& nums,vector<int>& result,vector<int>& temp,int i,int prev){
        if(i>=nums.size()){
            if(temp.size()>result.size())
                result=temp;
            return;
        }
        if(prev==-1 || nums[i] % prev==0){
            temp.push_back(nums[i]);
            solve(nums,result,temp,i+1,nums[i]);

            temp.pop_back();
        }
        solve(nums,result,temp,i+1,prev);
    }

    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        // vector<int> result;
        // vector<int> temp;


        // solve(nums,result,temp,0,-1);

        int n=nums.size();

        vector<int> t(n,1);

        vector<int> prev(n,-1);

        int last=0;
        int maxl=1;

        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i] % nums[j]==0){
                   if(t[i]<t[j]+1) {
                        t[i]=t[j]+1;
                        prev[i]=j;
                    }


                    if(t[i]>maxl){
                        maxl=t[i];
                        last=i;
                    }
                }

               
            }
        }


        vector<int> result;


        while(last!=-1){
            result.push_back(nums[last]);
            last=prev[last];
        }



        return result;
    }
};