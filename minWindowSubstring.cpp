#include <bits/stdc++.h>
using namespace std;

// Function to find the minimum window substring of s containing all characters of t
string minWindow(string s, string t) {
    unordered_map<char, int> freq;  // Map to store the required frequency of each character in t

    // Count frequency of each character in t
    for(char c : t) {
        freq[c]++;
    }

    int left = 0;           // Left pointer of sliding window
    int minLen = INT_MAX;   // Length of the smallest valid window found
    int start = 0;          // Start index of the smallest window
    int count = 0;          // Number of characters from t currently in the window

    // Expand the window with right pointer
    for(int right = 0; right < s.size(); right++) {
        char curr = s[right];

        // If this character is still needed, increment count
        if(freq[curr] > 0) {
            count++;
        }

        // Decrease the frequency of current character
        freq[curr]--;

        // Try to shrink the window from the left while it contains all characters of t
        while(count == t.size()) {
            // Update minimum window if current window is smaller
            if(minLen > right - left + 1) {
                minLen = right - left + 1;
                start = left;
            }

            char leftChar = s[left];  // Character at left pointer
            freq[leftChar]++;          // Put it back in the map

            // If this character is needed in the window, reduce count
            if(freq[leftChar] > 0) {
                count--;
            }

            left++;  // Shrink the window from the left
        }
    }

    // If no valid window was found, return a space
    if(minLen == INT_MAX) return " ";

    // Return the minimum window substring
    return s.substr(start, minLen);
}
