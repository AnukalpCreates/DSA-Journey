class Solution {
public:
    int countPrimes(int n) {
        if (n <= 2) return 0;

        // vector<bool> is space-optimized (1 bit per element) and cache-friendly
        vector<bool> isPrime(n, true);
        isPrime[0] = isPrime[1] = false;

        for (int i = 2; i * i < n; i++) {
            if (isPrime[i]) {
                // Step by 2*i if i is odd to avoid visiting even multiples
                int step = (i == 2) ? 2 : 2 * i;
                for (int j = i * i; j < n; j += step) {
                    isPrime[j] = false;
                }
            }
        }

        int count = 0;
        for (int i = 2; i < n; i++) {
            if (isPrime[i]) count++;
        }

        return count;
    }
};