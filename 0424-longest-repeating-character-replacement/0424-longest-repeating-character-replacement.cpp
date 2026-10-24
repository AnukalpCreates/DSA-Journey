class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int l = 0, r = 0;
        int maxLen = 0;
        int maxf = 0;
        vector<int> hash(26, 0);

        while (r < n) {
            hash[s[r] - 'A']++;
            maxf = max(maxf, hash[s[r] - 'A']);

            // If changes required exceed k, shrink window by 1 from left
            if ((r - l + 1) - maxf > k) {
                hash[s[l] - 'A']--;
                l++;
            }

            // Window is valid
            if ((r - l + 1) - maxf <= k) {
                maxLen = max(maxLen, r - l + 1);
            }

            r++;
        }
        return maxLen;
    }
};