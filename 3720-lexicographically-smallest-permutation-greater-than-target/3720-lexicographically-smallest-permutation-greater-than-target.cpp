class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int cnt[26] = {};
        for (char c : s)
            cnt[c - 'a']++;
        string ans;
        for (int i = 0; i < target.size(); i++) {
            int t = target[i] - 'a';
            if (cnt[t] > 0) {
                ans += target[i];
                cnt[t]--;
                continue;
            }
            for (int c = t + 1; c < 26; c++) {
                if (cnt[c] > 0) {
                    ans += char('a' + c);
                    cnt[c]--;
                    for (int x = 0; x < 26; x++) {
                        while (cnt[x]--) {
                            ans += char('a' + x);
                        }
                    }
                    return ans;
                }
            }
            break;
        }
        while (!ans.empty()) {
            int pos = ans.size() - 1;
            cnt[ans[pos] - 'a']++;
            ans.pop_back();
            int t = target[pos] - 'a';
            for (int c = t + 1; c < 26; c++) {
                if (cnt[c] > 0) {
                    ans += char('a' + c);
                    cnt[c]--;
                    for (int x = 0; x < 26; x++) {
                        while (cnt[x] > 0) {
                            ans += char('a' + x);
                            cnt[x]--;
                        }
                    }
                    return ans;
                }
            }
        }
        return "";
    }
};