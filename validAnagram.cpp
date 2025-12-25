#include <string>
#include <vector>
using namespace std;

// Function to check if two strings are anagrams
bool isAnagram(string s, string t) {
    // An anagram must have the same length
    if (s.size() != t.size()) {
        return false;
    }

    vector<int> count(26, 0); // Count array for 26 lowercase letters

    // Count frequency of each character in string s
    for (char c : s) {
        count[c - 'a']++;      // Increment count for this character
    }

    // Subtract frequency of each character in string t
    for (char c : t) {
        count[c - 'a']--;      // Decrement count for this character
    }

    // If all counts are zero, s and t are anagrams
    for (int freq : count) {
        if (freq != 0) {       // If any frequency is not zero
            return false;      // Strings are not anagrams
        }
    }

    return true;               // Strings are anagrams
}






// 2nd approach

bool isAnagram(string s, string t) {
    if (s.size() != t.size()) return false;

    sort(s.begin(), s.end());
    sort(t.begin(), t.end());

    return s == t;
}



// using hashmap



bool isAnagram(string s, string t) {
    if (s.size() != t.size()) return false;

    unordered_map<char,int> mp;

    for (char c : s) mp[c]++;
    for (char c : t) mp[c]--;

    for (auto &p : mp)
        if (p.second != 0) return false;

    return true;
}

