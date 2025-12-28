class Solution {
public:
    int romanToInt(string s) {

        // Map every Roman character to its integer value.
        // unordered_map gives O(1) lookup time.
        unordered_map<char, int> val = {
            {'I', 1},   // 1
            {'V', 5},   // 5
            {'X', 10},  // 10
            {'L', 50},  // 50
            {'C', 100}, // 100
            {'D', 500}, // 500
            {'M', 1000} // 1000
        };

        // This will store our final answer.
        int result = 0;

        // Traverse the string from left → right
        for (int i = 0; i < s.size(); i++) {

            // value of current Roman character
            int curr = val[s[i]];

            // value of next Roman character (if it exists)
            // if i+1 goes out of bounds, treat next as 0
            int next = (i + 1 < s.size()) ? val[s[i + 1]] : 0;

            /*
               IMPORTANT RULE:
               ----------------
               If the current value is LESS than the next value,
               that means we need to SUBTRACT.

               Examples:
                   IV  -> 1 < 5  -> subtract 1  (5 - 1 = 4)
                   IX  -> 1 < 9  -> subtract 1
                   XL  -> 10 < 50 -> subtract 10

               Otherwise, we simply ADD the current value.
            */

            if (curr < next) {
                // subtract because it is part of a "special pair"
                result -= curr;
            } else {
                // normal case: just add
                result += curr;
            }
        }

        // return the final computed integer
        return result;
    }
};
