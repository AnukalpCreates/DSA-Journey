class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> st; // Using a vector as a stack so we can easily return the result
        
        for (int i = 0; i < asteroids.size(); i++) {
            // If the asteroid is moving right, push it to the stack
            if (asteroids[i] > 0) {
                st.push_back(asteroids[i]);
            } else {
                // If the asteroid is moving left, check for collisions
                while (!st.empty() && st.back() > 0 && st.back() < abs(asteroids[i])) {
                    st.pop_back(); // The right-moving asteroid is smaller, so it explodes
                }
                
                if (!st.empty() && st.back() == abs(asteroids[i])) {
                    st.pop_back(); // Both are same size, both explode
                } else if (st.empty() || st.back() < 0) {
                    st.push_back(asteroids[i]); // No collision, push the left-moving asteroid
                }
            }
        }
        
        return st;
    }
};