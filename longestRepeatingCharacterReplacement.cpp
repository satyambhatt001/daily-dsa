/* Input: s = "XYYX", k = 2

Output: 4 */

//bruteforce
class Solution {
public:
    int characterReplacement(string s, int k) {
           int n = s.size();
        int maxLen = 0;

        for (int i = 0; i < n; i++) {
            vector<int> freq(26, 0);

            for (int j = i; j < n; j++) {
                freq[s[j] - 'A']++;

                int maxFreq = 0;
                for (int c = 0; c < 26; c++) {
                    maxFreq = max(maxFreq, freq[c]);
                }

                int len = j - i + 1;
                int replacementsNeeded = len - maxFreq;

                if (replacementsNeeded <= k) {
                    maxLen = max(maxLen, len);
                }
            }
        }

        return maxLen;
    }
};

//optimal

class Solution {
public:
    int characterReplacement(string s, int k) {

        // Frequency array for 26 uppercase English letters
        // freq[0] → count of 'A'
        // freq[1] → count of 'B'
        // ...
        vector<int> freq(26, 0);

        // Left pointer of sliding window
        int left = 0;

        // maxFreq stores the count of the MOST frequent character
        // inside the current window
        int maxFreq = 0;

        // Stores the maximum valid window length found so far
        int maxLen = 0;

        // Right pointer expands the window
        for (int right = 0; right < s.size(); right++) {

            // Convert character to index (A→0, B→1...)
            // Increase frequency of current character
            freq[s[right] - 'A']++;

            // Update maxFreq if this character becomes most frequent
            // We ONLY increase maxFreq (never decrease)
            maxFreq = max(maxFreq, freq[s[right] - 'A']);

            /*
             Window validity condition:

             replacementsNeeded = windowSize - maxFreq

             Why?
             - maxFreq = count of char we KEEP
             - Others must be replaced

             If replacementsNeeded > k → INVALID window
             */

            while ((right - left + 1) - maxFreq > k) {

                // Remove leftmost character from window
                freq[s[left] - 'A']--;

                // Shrink window by moving left pointer
                left++;
            }

            // Window is valid here → update answer
            maxLen = max(maxLen, right - left + 1);
        }

        // Return longest valid substring length
        return maxLen;
    }
};
