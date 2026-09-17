class Solution {
public:
    long long sumSubarrayMins(vector<int>& nums) {
        int n = nums.size();
        vector<int> prev_smaller(n), next_smaller(n);
        stack<int> st;

        // Previous Smaller Element (or equal)
        for (int i = 0; i < n; i++) {
            while (!st.empty() && nums[st.top()] > nums[i]) {
                st.pop();
            }
            prev_smaller[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        while (!st.empty()) st.pop();

        // Next Smaller Element (strictly smaller)
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && nums[st.top()] >= nums[i]) {
                st.pop();
            }
            next_smaller[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        long long total = 0;
        for (int i = 0; i < n; i++) {
            long long left = i - prev_smaller[i];
            long long right = next_smaller[i] - i;
            total += left * right * nums[i];
        }
        return total;
    }

    long long sumSubarrayMaxs(vector<int>& nums) {
        int n = nums.size();
        vector<int> prev_greater(n), next_greater(n);
        stack<int> st;

        // Previous Greater Element (or equal)
        for (int i = 0; i < n; i++) {
            while (!st.empty() && nums[st.top()] < nums[i]) {
                st.pop();
            }
            prev_greater[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        while (!st.empty()) st.pop();

        // Next Greater Element (strictly greater)
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && nums[st.top()] <= nums[i]) {
                st.pop();
            }
            next_greater[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        long long total = 0;
        for (int i = 0; i < n; i++) {
            long long left = i - prev_greater[i];
            long long right = next_greater[i] - i;
            total += left * right * nums[i];
        }
        return total;
    }
    long long subArrayRanges(vector<int>& nums) {
        return sumSubarrayMaxs(nums) - sumSubarrayMins(nums);
    }

    
};