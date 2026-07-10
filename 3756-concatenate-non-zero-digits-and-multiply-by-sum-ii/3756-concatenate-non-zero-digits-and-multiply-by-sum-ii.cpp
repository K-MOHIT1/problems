class Solution {
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int mod = 1e9 + 7;
        int n = s.size();

        vector<int> sum(n, 0);
        vector<long long> dig(n);
        vector<int> k(n, 0);
        vector<long long> p10(n + 1);
        p10[0] = 1;
        for (int i = 1; i <= n; i++) {
            p10[i] = (p10[i - 1] * 10LL) % mod;
        }
        for (int i = 0; i < n; i++) {
            if (i > 0)
                sum[i] = sum[i - 1] + (s[i] - '0');
            else
                sum[i] = s[i] - '0';
        }

        long long num = 0;
        dig[0] = s[0] - '0';
        num = dig[0];
        if (num != 0)
            k[0] = 1;

        for (int i = 1; i < n; i++) {
            if (s[i] != '0') {
                num = (num * 10LL + (s[i] - '0')) % mod;
                k[i] = 1;
            }
            dig[i] = num;
            k[i] += k[i - 1];
        }

        vector<int> ans;

        for (int i = 0; i < queries.size(); i++) {
            int le = queries[i][0];
            int rg = queries[i][1];

            int sm = sum[rg] - (le == 0 ? 0 : sum[le - 1]);
            int kin = k[rg] - (le == 0 ? 0 : k[le - 1]);

            long long number = dig[rg];
            if (le != 0) {
                number = (number - (dig[le - 1] * p10[kin]) % mod + mod) % mod;
            }

            cout << sm << " " << number << " " << kin << endl;

            long long pi = (1LL * sm * number) % mod;
            ans.push_back((int)pi);
        }

        return ans;
    }
};