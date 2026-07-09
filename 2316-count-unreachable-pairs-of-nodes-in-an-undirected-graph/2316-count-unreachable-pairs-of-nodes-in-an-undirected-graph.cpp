class Solution {
public:

    int find(int x, vector<int>& parent) {
        if (x == parent[x]) return x;
        return parent[x] = find(parent[x], parent);
    }

    void Union(int x, int y, vector<int>& rank, vector<int>& parent) {
        int px = find(x, parent);
        int py = find(y, parent);

        if (px == py) return;

        if (rank[px] < rank[py]) {
            parent[px] = py;
        }
        else if (rank[px] > rank[py]) {
            parent[py] = px;
        }
        else {
            parent[py] = px;
            rank[px]++;
        }
    }

    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<int> rank(n, 0);
        vector<int> parent(n);

        for (int i = 0; i < n; i++)
            parent[i] = i;

        for (auto &x : edges) {
            Union(x[0], x[1], rank, parent);
        }

        unordered_map<int, int> mp;

        for (int i = 0; i < n; i++) {
            mp[find(i, parent)]++;
        }

        long long ans = 0;
        long long sz = n;

        for (auto &x : mp) {
            long long u = x.second;
            ans += u * (sz - u);
            sz -= u;
        }

        return ans;
    }
};