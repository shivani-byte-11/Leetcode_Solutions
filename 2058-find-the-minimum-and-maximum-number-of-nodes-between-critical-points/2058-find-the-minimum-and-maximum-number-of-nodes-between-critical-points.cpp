/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int first = -1;
        int last = -1;
        int minDist = INT_MAX;
        int index = 1;
        ListNode* prev = head;
        ListNode* curr = head->next;
        while (curr->next != nullptr) {
            bool critical =
                (curr->val > prev->val && curr->val > curr->next->val) ||
                (curr->val < prev->val && curr->val < curr->next->val);
            if (critical) {
                if (first == -1) {
                    first = index;
                }
                if (last != -1) {
                    minDist = min(minDist, index - last);
                }
                last = index;
            }
            prev = curr;
            curr = curr->next;
            index++;
        }
        if (first == last) {
            return {-1, -1};
        }
        int maxDist = last - first;
        return {minDist, maxDist};
    }
};