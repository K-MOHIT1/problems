class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int ans=0;
        sort(intervals.begin(),intervals.end(),[](vector<int>& a,vector<int>& b){
            if(a[0]==b[0]) return a[1]>b[1];
            return a[0]<b[0];
        });
        int maxi=0;


        for(vector<int> x:intervals){
            if(x[1]>maxi){
                ans++;
                maxi=x[1];
            }
        }
        return ans;

    }
};