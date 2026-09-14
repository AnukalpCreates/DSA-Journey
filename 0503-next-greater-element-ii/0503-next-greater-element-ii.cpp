class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> nge(n);
        stack<int> st;

        // Hypothetically traverse a doubled array from right to left
        for (int i = 2 * n - 1; i >= 0; i--) {
            // Pop elements that are smaller than or equal to current element
            while (!st.empty() && st.top() <= nums[i % n]) {
                st.pop();
            }

            // Only fill results during the first pass (i < n)
            if (i < n) {
                nge[i] = st.empty() ? -1 : st.top();
            }

            // Push current element to maintain monotonic decreasing stack
            st.push(nums[i % n]);
        }

        return nge;
    }
};