class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n = word1.length();
        int m = word2.length();
        vector<int> last(m + 1, -1);
        last[m] = n;
        for (int i = n - 1, j = m - 1; i >= 0 && j >= 0; i--) {
            if (word1[i] == word2[j]) {
                last[j] = i;
                j--;
            }
        }
        vector<int> ans;
        bool changed = false; 
        int i = 0, j = 0;
        while (i < n && j < m) {
            if (word1[i] == word2[j]) {
                ans.push_back(i);
                i++;
                j++;
            } 
            else if (!changed && last[j + 1] > i) {
                ans.push_back(i);
                changed = true;
                i++;
                j++;
            } 
            else {
                i++;
            }
        }
        return ans.size() == m ? ans : vector<int>{};
    }
};