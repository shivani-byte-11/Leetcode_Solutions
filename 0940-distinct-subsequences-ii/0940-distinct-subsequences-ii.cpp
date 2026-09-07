class Solution {
public:
    int distinctSubseqII(string s) {
        const long long MOD = 1e9 + 7;
        vector<long long> dp(26, 0);
        for (char c : s) {
            int idx = c - 'a';
            long long total = 1;
            for (int x : dp) {
                total = (total + x) % MOD;
            }
            dp[idx] = total;
        }
        long long ans = 0;
        for (long long x : dp) {
            ans = (ans + x) % MOD;
        }
        return ans;
    }
};