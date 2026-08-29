class Solution {
public:
    vector<string> ans;
    vector<string> addOperators(string num, int target) {
        helper(num, target, 0, "", 0, 0);
        return ans;
    }
    void helper(string num, int target, int i, const string& path, long eval, long residual) {
        // bc
        if (i == num.length()) {
            if (eval == target) {
                ans.push_back(path);
            }
            return;
        }

        string currStr;
        long nums = 0;
        
        // backtracking loop
        for (int j = i; j < num.length(); j++) {
            // handle leading zero
            if (j > i && num[i] == '0') return;
            
            currStr += num[j];
            nums = nums * 10 + num[j] - '0';
            
            if (i == 0) {
                helper(num, target, j + 1, path + currStr, nums, nums);
            } else {
                helper(num, target, j + 1, path + "+" + currStr, eval + nums, nums);
                helper(num, target, j + 1, path + "-" + currStr, eval - nums, -nums);
                helper(num, target, j + 1, path + "*" + currStr, eval - residual + residual * nums, residual * nums);
            }
        }
    }
};