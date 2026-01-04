// Function to find the single element in an array
// where every other element appears twice except one.
int single(vector<int>& nums) {
    // Initialize the answer with 0.
    // We'll use XOR property to cancel out duplicate numbers.
    int ans = 0;

    // Loop through every number in the array
    for (int num : nums) {
        /*
          XOR (^) properties we are using here:
          1. x ^ x = 0   (any number XOR with itself is 0)
          2. x ^ 0 = x   (any number XOR with 0 remains same)
          3. XOR is commutative and associative 
             (order does not matter)

          So, if we XOR all numbers:
          - The numbers appearing twice will cancel each other to 0
          - The unique number will remain because x ^ 0 = x
        */

        ans ^= num;  // Keep XORing numbers
    }

    // After the loop, ans will hold the unique element
    return ans;
}
