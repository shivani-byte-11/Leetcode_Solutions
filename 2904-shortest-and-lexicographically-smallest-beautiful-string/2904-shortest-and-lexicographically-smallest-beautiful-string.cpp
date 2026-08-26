class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.size();
        int left = 0;
        int ones = 0;
        string ans = "";
        int minLen = INT_MAX;
        for (int right = 0; right < n; right++) {
            if (s[right] == '1')
                ones++;
            while (ones > k) {
                if (s[left] == '1')
                    ones--;
                left++;
            }
            while (ones == k && s[left] == '0') {
                left++;
            }
            if (ones == k) {
                string curr = s.substr(left, right - left + 1);
                if (curr.length() < minLen) {
                    minLen = curr.length();
                    ans = curr;
                }
                else if (curr.length() == minLen && curr < ans) {
                    ans = curr;
                }
            }
        }
        return ans;
    }
};