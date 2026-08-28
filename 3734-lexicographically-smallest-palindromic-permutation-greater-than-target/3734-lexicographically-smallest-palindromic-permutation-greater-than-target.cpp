class Solution {
public:
    string lexPalindromicPermutation(string s, string target) {
        int n = s.size();
        vector<int> cnt(26, 0);
        for (char c : s)
            cnt[c - 'a']++;
        int odd = 0;
        char mid = 0;
        for (int i = 0; i < 26; i++) {
            if (cnt[i] % 2) {
                odd++;
                mid = 'a' + i;
            }
        }
        if (odd > 1)
            return "";
        vector<int> half(26);
        for (int i = 0; i < 26; i++)
            half[i] = cnt[i] / 2;
        int halfLen = n / 2;
        string left;
        for (int pos = 0; pos < halfLen; pos++) {
            bool found = false;
            for (int c = 0; c < 26; c++) {
                if (half[c] == 0)
                    continue;
                half[c]--;
                left.push_back('a' + c);
                string temp = left;
                for (int x = 25; x >= 0; x--) {
                    temp += string(half[x], 'a' + x);
                }
                string pal = temp;
                if (n % 2)
                    pal += mid;
                for (int i = temp.size() - 1; i >= 0; i--)
                    pal += temp[i];
                if (pal > target) {
                    found = true;
                    break;
                }
                left.pop_back();
                half[c]++;
            }
            if (!found)
                return "";
        }
        string ans = left;
        if (n % 2)
            ans += mid;
        for (int i = left.size() - 1; i >= 0; i--)
            ans += left[i];
        return ans > target ? ans : "";
    }
};