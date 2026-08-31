class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        int subsetsCount = 1 << n; // Total subsets = 2^n
        vector<vector<int>> ans;

        for (int num = 0; num < subsetsCount; num++) {
            vector<int> currentSubset;
            for (int i = 0; i < n; i++) {
                // Check if the i-th bit of 'num' is set
                if (num & (1 << i)) {
                    currentSubset.push_back(nums[i]);
                }
            }
            ans.push_back(currentSubset);
        }

        return ans;
    }
};