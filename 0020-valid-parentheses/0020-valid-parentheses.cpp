class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for (int i = 0; i < s.length(); i++) {
            // If opening bracket, push to stack
            if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
                st.push(s[i]);
            } 
            else {
                // If closing bracket arrives and stack is empty, it's unbalanced
                if (st.empty()) return false;

                char ch = st.top();
                st.pop();

                // Check if top matches current closing bracket
                if ((s[i] == ')' && ch == '(') || 
                    (s[i] == ']' && ch == '[') || 
                    (s[i] == '}' && ch == '{')) {
                    continue;
                } 
                else {
                    return false;
                }
            }
        }
        return st.empty();
    }
};