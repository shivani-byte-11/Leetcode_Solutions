class Solution {
public:
    int tribonacci(int n) {
        vector<int> dp(n+1, 0);
        int prev2 = 0;
        int prev1 = 1;
        int prev = 1;
        if(n==0) return 0;
        for(int i=3; i<=n; i++){
            int  curr = prev2 + prev1 + prev;
            prev2 = prev1;
            prev1 = prev;
            prev = curr;
        }
        return prev;
    }
};