class Solution {
public:
    static bool comp(vector<int>& a, vector<int>& b) {
        return a[1] > b[1];   // Sort by units per box in descending order
    }

    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(), comp);

        int ans = 0;

        for (auto &box : boxTypes) {
            int boxes = min(box[0], truckSize);

            ans += boxes * box[1];
            truckSize -= boxes;

            if (truckSize == 0)
                break;
        }

        return ans;
    }
};