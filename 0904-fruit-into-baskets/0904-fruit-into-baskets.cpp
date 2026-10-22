class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int l = 0, r = 0, maxLen = 0;
        unordered_map<int, int> mpp;
        int n = fruits.size();

        while (r < n) {
            mpp[fruits[r]]++;

            // If the map has more than 2 types of fruits, shrink the window from the left
            if (mpp.size() > 2) {
                mpp[fruits[l]]--;
                if (mpp[fruits[l]] == 0) {
                    mpp.erase(fruits[l]);
                }
                l++;
            }

            // If the window size is valid (at most 2 types of fruits)
            if (mpp.size() <= 2) {
                maxLen = max(maxLen, r - l + 1);
            }
            
            r++;
        }
        return maxLen; 
    }
};