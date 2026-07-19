class Solution {
public:
    int dp[2501][2502];

    int recur(vector<int>& nums, int i, int prev) {
        if (i == nums.size())
            return 0;

        if (dp[i][prev + 1] != -1)
            return dp[i][prev + 1];

        int skip = recur(nums, i + 1, prev);

        int take = 0;
        if (prev == -1 || nums[i] > nums[prev]) {
            take = 1 + recur(nums, i + 1, i);
        }

        return dp[i][prev + 1] = max(skip, take);
    }

    int lengthOfLIS(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        return recur(nums, 0, -1);
    }
};