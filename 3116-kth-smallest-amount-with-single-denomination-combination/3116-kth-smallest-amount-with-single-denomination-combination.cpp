class Solution {
public:
    long long findKthSmallest(vector<int>& coins, int k) {
        int n = coins.size();
        int total = 1 << n;
        vector<long long> lcm(total, 1);
        for (int mask = 1; mask < total; mask++) {
            int bit = __builtin_ctz(mask);
            int prev = mask ^ (1 << bit);
            lcm[mask] = std::lcm(lcm[prev], (long long)coins[bit]);
            if (lcm[mask] > 1e18)
                lcm[mask] = 1e18;
        }
        auto count = [&](long long x) {
            long long cnt = 0;
            for (int mask = 1; mask < total; mask++) {
                if (lcm[mask] > x)
                    continue;
                long long val = x / lcm[mask];
                if (__builtin_popcount(mask) & 1)
                    cnt += val;
                else
                    cnt -= val;
            }
            return cnt;
        };
        long long lo = 1;
        long long hi = 1LL * k * (*min_element(coins.begin(), coins.end()));
        while (lo < hi) {
            long long mid = lo + (hi - lo) / 2;
            if (count(mid) >= k)
                hi = mid;
            else
                lo = mid + 1;
        }
        return lo;
    }
};