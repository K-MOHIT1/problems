class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans;
        set<int> s;

        int sm=INT_MAX;
        int lg=INT_MIN;
        for(int i=0;i<n;i++){
            s.insert(nums[i]);
            sm=min(sm,nums[i]);
            lg=max(lg,nums[i]);
        }

        for(int i=sm;i<lg;i++){
            if(s.find(i)==s.end()) ans.push_back(i);
        }

        return ans;
    }
};