class Solution {
public:
    unordered_set<string> st;
    int n;
    int t[301]; // Memoization table (since s.length <= 300)

    bool solve(int idx, string &s) {
        // Base Case: Reached the end of the string
        if (idx >= n) {
            return true;
        }

        // Return memoized result if already computed
        if (t[idx] != -1) {
            return t[idx];
        }

        // Try partitioning substrings starting from idx of length l
        for (int l = 1; l <= n - idx; l++) {
            string temp = s.substr(idx, l);

            if (st.find(temp) != st.end() && solve(idx + l, s)) {
                return t[idx] = true;
            }
        }

        return t[idx] = false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        n = s.length();
        memset(t, -1, sizeof(t));

        // Insert all dictionary words into an unordered_set for O(1) lookup
        for (string &word : wordDict) {
            st.insert(word);
        }

        return solve(0, s);
    }
};