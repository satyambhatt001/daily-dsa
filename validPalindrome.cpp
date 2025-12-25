#include <string>
#include <cctype> // for isalnum() and tolower()
using namespace std;

// Function to check if a string is a palindrome (ignoring case and non-alphanumeric characters)
bool isValid(string s) {
    int left = 0;               // Start pointer at beginning of string
    int right = s.size() - 1;   // End pointer at last character

    while(left < right) {       // Continue until the two pointers meet or cross
        // Move left pointer forward if current character is not alphanumeric
        while(left < right && !isalnum(s[left])) {
            left++;             // Skip non-alphanumeric characters
        }

        // Move right pointer backward if current character is not alphanumeric
        while(left < right && !isalnum(s[right])) {
            right--;            // Skip non-alphanumeric characters
        }

        // Compare characters ignoring case
        if(tolower(s[left]) != tolower(s[right])) {
            return false;       // If mismatch found, string is not a palindrome
        }

        // Move both pointers towards center
        left++;
        right--;
    }

    // If we reach here, all characters matched
    return true;
}


//using revverse fun

bool isPalindrome(string s) {
    string t;
    for (auto c : s) {
        if (isalnum((unsigned char)c)) {
            t.push_back(tolower((unsigned char)c));
        }
    }

    string r = t;
    reverse(r.begin(), r.end());

    if (r != t) return false;
    return true;
}




//2nd my approach

bool isPalindrome(string s) {
    string t;

    for (auto c : s) {
        if (isalnum((unsigned char)c)) {
            t.push_back(tolower((unsigned char)c));
        }
    }

    string r;

    // build r from the back of t
    for (int i = t.size() - 1; i >= 0; i--) {
        r.push_back(t[i]);
    }

    return t == r;
}


