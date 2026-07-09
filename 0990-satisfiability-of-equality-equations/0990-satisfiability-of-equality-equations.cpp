class Solution {
public:
    int find(int x, vector<int>& parent) {
        if (parent[x] == x)
            return x;

        return parent[x] = find(parent[x], parent);
    }

    void Union(int x, int y, vector<int>& parent, vector<int>& rank) {
        int px = find(x, parent);
        int py = find(y, parent);

        if (px == py)
            return;

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

    bool equationsPossible(vector<string>& equations) {
        vector<int> parent(26);
        vector<int> rank(26, 0);

        for (int i = 0; i < 26; i++)
            parent[i] = i;

        for (auto &eq : equations) {
            if (eq[1] == '=') {
                Union(eq[0] - 'a', eq[3] - 'a', parent, rank);
            }
        }

        for (auto &eq : equations) {
            if (eq[1] == '!') {
                int x = find(eq[0] - 'a', parent);
                int y = find(eq[3] - 'a', parent);

                if (x == y)
                    return false;
            }
        }

        return true;
    }
};