class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long xorr = 0;
        int n = nums.size();

        // Loop 1: XOR all elements
        for (int i = 0; i < n; i++) {
            xorr ^= nums[i];
        }
        
        // Isolate the rightmost set bit
        long rightmost = (xorr & (xorr - 1)) ^ xorr;
        
        int b1 = 0;
        int b2 = 0;
        
        // Loop 2: Partition numbers into two buckets
        for (int i = 0; i < n; i++) {
            if (nums[i] & rightmost) {
                b1 ^= nums[i];
            } else {
                b2 ^= nums[i];
            }
        }
        
        return {b1, b2};

    }
};