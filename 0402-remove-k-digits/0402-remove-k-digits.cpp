class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;
        int n = num.length();
        
        // Step 1: Build the stack with the smallest possible digits
        for(int i = 0; i < n; i++) {
            while (!st.empty() && k > 0 && (st.top() - '0') > (num[i] - '0')) {
                st.pop();
                k = k - 1;
            }
            st.push(num[i]);
        }
        
        // Step 2: If we still need to remove digits, remove from the end
        while (k > 0) {
            st.pop();
            k--;
        }
        
        // Step 3: If stack is empty, return "0"
        if (st.empty()) {
            return "0";
        }
        
        // Step 4: Retrieve the characters from the stack
        string res = "";
        while (!st.empty()) {
            res += st.top();
            st.pop();
        }
        
        // Step 5: Remove trailing zeros (which are actually leading zeros since the string is reversed)
        while (res.size() != 0 && res.back() == '0') {
            res.pop_back();
        }
            
        // Step 6: Reverse the string to get the correct order
        reverse(res.begin(), res.end());
        
        // Step 7: Handle the edge case where the result becomes empty after stripping zeros
        if (res.empty()) {
            return "0";
        }
        
        return res;
    }
};