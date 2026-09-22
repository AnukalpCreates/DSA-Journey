class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> list; 
        deque<int> dq;
        int n = nums.size();
        
        for (int i = 0; i < n; i++) {
            // Remove out of bound elements
            if (!dq.empty() && dq.front() == i - k) {
                dq.pop_front();
            }
            
            // Remove smaller elements
            while (!dq.empty() && nums[dq.back()] <= nums[i]) {
                dq.pop_back();
            }
            
            // Push current index (Striver wrote dq.push(i), valid C++ is push_back)
            dq.push_back(i);
            
            // Include maximum in the list (Striver wrote list.add(), valid C++ is push_back)
            if (i >= k - 1) {
                list.push_back(nums[dq.front()]);
            }
        }
        
        return list;
    }
};