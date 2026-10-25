class Solution {
public:
    int helper(vector<int>& nums, int goal) {
        if (goal < 0) return 0;
        int l = 0, r = 0, sum = 0, cnt = 0;
        int n = nums.size();
        while (r < n) {
            sum += (nums[r] % 2);
            while (sum > goal) {
                sum -= (nums[l] % 2);
                l = l + 1;
            }
            cnt = cnt + (r - l + 1);
            r = r + 1;
        }
        return cnt;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return helper(nums, k) - helper(nums, k - 1);
    
    }
};