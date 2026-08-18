class Solution {
public:
    vector<string> result;

    void solve(string &curr, int n, int open, int close) {

        // Base case
        if (curr.length() == 2 * n) {
            result.push_back(curr);
            return;
        }

        // We can add '(' if we haven't used all n opening brackets
        if (open < n) {
            curr.push_back('(');

            solve(curr, n, open + 1, close);

            curr.pop_back();   // backtrack
        }

        // We can add ')' only when there is an unmatched '('
        if (close < open) {
            curr.push_back(')');

            solve(curr, n, open, close + 1);

            curr.pop_back();   // backtrack
        }
    }
    vector<string> generateParenthesis(int n) {
        string curr = "";

        solve(curr, n, 0, 0);

        return result;
    }
};