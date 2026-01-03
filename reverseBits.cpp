#include <cstdint>  // for uint32_t

int hammingWeight(uint32_t n) {
    int count = 0;   // count how many 1 bits

    // keep shifting n until it becomes 0
    while (n != 0) {
        // (n & 1) extracts the last bit of n
        // if last bit = 1, add 1 to count, else add 0
        count += (n & 1);

        // shift n right by 1, discarding the last bit we just checked
        n >>= 1;
    }

    return count; // return total number of 1s
}
