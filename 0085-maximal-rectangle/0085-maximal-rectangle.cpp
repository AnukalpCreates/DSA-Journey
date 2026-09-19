class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> st;
        int maxArea = 0;
        
        for (int i = 0; i <= n; i++) {
            while (!st.empty() && (i == n || heights[st.top()] >= heights[i])) {
                int height = heights[st.top()];
                st.pop();
                int width;
                if (st.empty()) {
                    width = i;
                } else {
                    width = i - st.top() - 1;
                }
                maxArea = max(maxArea, width * height);
            }
            st.push(i);
        }
        return maxArea;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty()) return 0;
        
        int n = matrix.size();
        int m = matrix[0].size();
        int maxArea = 0;
        vector<int> height(m, 0); // Acts as the psum array shown in the video
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                // If the matrix has a '1', increase the height of the histogram column
                // If it has a '0', reset the height to 0
                if (matrix[i][j] == '1') {
                    height[j]++;
                } else {
                    height[j] = 0;
                }
            }
            // Calculate the max area for the histogram formed at the current row
            int area = largestRectangleArea(height);
            maxArea = max(maxArea, area);
        }
        
        return maxArea;
    }
};