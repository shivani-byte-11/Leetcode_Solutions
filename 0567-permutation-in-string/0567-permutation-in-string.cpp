class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n=s1.size();
        int m=s2.size();
        vector<int> ans1(26,0);
        vector<int> ans2(26,0);
        if(n>m) return false;
        for(int i=0; i<n; i++){
            ans1[s1[i]-'a']++;
        }
        for(int i=0; i<n; i++){
            ans2[s2[i]-'a']++;
        }
        if(ans1==ans2) return true;
        int low=0, high=n-1;
        while(high<m-1){
            low++; high++;
            ans2[s2[high]-'a']++;
            ans2[s2[low-1]-'a']--;
            if(ans1==ans2) return true;
        }
        return false;
    }
};