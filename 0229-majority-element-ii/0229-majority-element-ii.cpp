class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> result;
        for(int i=0; i<nums.size(); i++){
            if(result.size()==0 || result[0] != nums[i]){
                int cnt = 0;
                for(int j=0; j<nums.size(); j++){
                    if(nums[i] == nums[j]){
                        cnt++;
                    }
                }
                if(cnt>nums.size()/3){
                    result.push_back(nums[i]);
                }
            }
            if(result.size() == 2) break;
        }
        return result;
    }
};