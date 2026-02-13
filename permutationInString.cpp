class Solution {
public:
    bool checkInclusion(string s1, string s2) {

        // Step 1: Get lengths of both strings
        int n1 = s1.size();   // length of s1
        int n2 = s2.size();   // length of s2

        // Step 2: If s1 is longer than s2,
        // it's impossible for s2 to contain a permutation of s1
        if (n1 > n2) 
            return false;

        // Step 3: Sort s1
        // Why? Because permutations of s1 will have the same sorted order
        // Example:
        // s1 = "ab"
        // permutations → "ab", "ba"
        // sorted → both become "ab"
        sort(s1.begin(), s1.end());

        // Step 4: Slide over s2 and check substrings of size n1
        // We only go until (n2 - n1), so substring doesn't overflow
        for (int i = 0; i <= n2 - n1; i++) {

            // Step 5: Extract substring of length n1 starting at index i
            // Example:
            // s2 = "eidbaooo", s1 length = 2
            // i = 3 → sub = "ba"
            string sub = s2.substr(i, n1);

            // Step 6: Sort the substring
            // If it is a permutation of s1,
            // its sorted version should match sorted s1
            sort(sub.begin(), sub.end());

            // Step 7: Compare sorted substring with sorted s1
            if (sub == s1) {

                // Found a permutation → return true immediately
                return true;
            }
        }

        // Step 8: No permutation found after checking all substrings
        return false;
    }
};
//2nd approach

 bool checkInclusion(string s1, string s2) {

    // ---------------------------------------------------
    // STEP 1: Basic size check
    // ---------------------------------------------------
    // If s1 is longer than s2,
    // s2 cannot possibly contain any permutation of s1.
    // Example:
    // s1 = "abcd" (length 4)
    // s2 = "ab"   (length 2)
    // Impossible → return false
    if (s1.size() > s2.size()) 
        return false;


    // ---------------------------------------------------
    // STEP 2: Create frequency arrays
    // ---------------------------------------------------
    // We assume strings contain only lowercase letters 'a' → 'z'
    // So we use arrays of size 26.
    //
    // f1 → frequency of characters in s1
    // f2 → frequency of characters in current window of s2
    //
    // Index mapping:
    // 'a' → 0
    // 'b' → 1
    // ...
    // 'z' → 25
    vector<int> f1(26, 0), f2(26, 0);


    // ---------------------------------------------------
    // STEP 3: Count frequency of s1
    // ---------------------------------------------------
    // We loop through s1 and increment counts.
    //
    // Example:
    // s1 = "aab"
    // f1['a'] = 2
    // f1['b'] = 1
    for (char c : s1)
        f1[c - 'a']++;   // Convert char → index


    // ---------------------------------------------------
    // STEP 4: Window size
    // ---------------------------------------------------
    // We will slide a window of size equal to s1
    int k = s1.size();


    // ---------------------------------------------------
    // STEP 5: Build frequency of FIRST window in s2
    // ---------------------------------------------------
    // Window = s2[0 ... k-1]
    //
    // Example:
    // s2 = "eidbaooo"
    // k = 2
    // first window = "ei"
    for (int i = 0; i < k; i++)
        f2[s2[i] - 'a']++;


    // ---------------------------------------------------
    // STEP 6: Compare first window
    // ---------------------------------------------------
    // If frequencies match → permutation found
    //
    // Why this works:
    // Two strings are permutations if their character counts match.
    if (f1 == f2) 
        return true;


    // ---------------------------------------------------
    // STEP 7: Slide the window across s2
    // ---------------------------------------------------
    // Start from index k (next character after first window)
    //
    // At each step:
    // 1. Add new character (right side of window)
    // 2. Remove old character (left side of window)
    //
    // This avoids recomputing frequency from scratch!
    for (int i = k; i < s2.size(); i++) {

        // -----------------------------------------------
        // Add new character entering the window
        // -----------------------------------------------
        // Example:
        // window moves right → include s2[i]
        f2[s2[i] - 'a']++;

        // -----------------------------------------------
        // Remove character leaving the window
        // -----------------------------------------------
        // Character at position (i - k) is no longer inside window
        f2[s2[i - k] - 'a']--;

        // -----------------------------------------------
        // Compare updated window frequency with s1
        // -----------------------------------------------
        if (f1 == f2) 
            return true;
    }


    // ---------------------------------------------------
    // STEP 8: No permutation found
    // ---------------------------------------------------
    return false;
}
