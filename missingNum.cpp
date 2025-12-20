#include <vector>
using namespace std;

int missing(vector<int>& nums) {
    int n = nums.size();

    // Start with res = n (because indices go from 0 to n-1,
    // but one number is from [0...n], so we must include n as well)
    int res = n;

    // Loop through the array
    for (int i = 0; i < n; i++) {
        /*
          XOR properties used:
          1. x ^ x = 0   (a number cancels with itself)
          2. x ^ 0 = x   (XOR with 0 keeps the number)
          3. XOR is commutative and associative (order doesn’t matter)

          We XOR all indices [0..n-1] and all numbers in nums.
          Since nums contains all numbers except one missing,
          everything cancels out except the missing number.
        */
        res ^= i ^ nums[i];
    }

    return res; // missing number remains
    
}
