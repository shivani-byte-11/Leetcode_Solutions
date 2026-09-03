class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int mx = *max_element(nums.begin(), nums.end());
        int n=nums.size();
        if(n==1) return nums[0];
        vector<int> freq(mx+1, 0);
        for(int num:nums){
            freq[num]++;
        }
        vector<int> dp(mx+1, 0);
        int prev2 = 0;
        int prev = 1*freq[1];
        for(int i=2; i<=mx; i++){
            int curr = max(prev, prev2+i*freq[i]);
            prev2=prev;
            prev=curr;
        }
        return prev;
    }
};