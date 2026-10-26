class Solution {
public:
    int helper(vector<int>& nums, int k) {
        if (k < 0) return 0;
        
        int l = 0, r = 0;
        int count = 0;
        unordered_map<int, int> mpp;
        int n = nums.size();

        while (r < n) {
            mpp[nums[r]]++;

            while (mpp.size() > k) {
                mpp[nums[l]]--;
                if (mpp[nums[l]] == 0) {
                    mpp.erase(nums[l]);
                }
                l++;
            }

            count += (r - l + 1);
            r++;
        }

        return count;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return helper(nums, k) - helper(nums, k - 1);
    }
};