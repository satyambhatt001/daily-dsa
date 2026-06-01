class Solution {
  public:
    int findMaxProduct(vector<int>& arr) {
        // code here
     int n = arr.size();
        long long MOD = 1e9 + 7;

        if (n == 1)
            return arr[0];

        int negativeCount = 0;
        int zeroCount = 0;
        int maxNegative = INT_MIN; // negative closest to 0

        // Pass 1: Gather information
        for (int x : arr) {
            if (x == 0) {
                zeroCount++;
            } else if (x < 0) {
                negativeCount++;
                maxNegative = max(maxNegative, x);
            }
        }

        // All elements are 0
        if (zeroCount == n)
            return 0;

        // Only one negative and rest are zeros
        if (negativeCount == 1 && zeroCount + negativeCount == n)
            return 0;

        long long product = 1;
        bool skippedMaxNegative = false;

        // Pass 2: Calculate product modulo 1e9 + 7
        for (int x : arr) {
            if (x == 0) continue;

            // If odd negatives, skip exactly ONE instance of the maxNegative
            if (negativeCount % 2 == 1 && x == maxNegative && !skippedMaxNegative) {
                skippedMaxNegative = true;
                continue;
            }

            // Multiply and immediately apply modulo to prevent overflow
            product = (product * (long long)x) % MOD;
        }

        
        if (product < 0) {
            product = (product + MOD) % MOD;
        }

        return product;
    }
};
