// Function to check if a string is made by repeating a substring
bool repeated(string &s) {
    // Edge case: empty string cannot be "repeated"
    if (s.empty())
        return false;

    // Double the string (e.g., "abab" -> "abababab")
    string doubled = s + s;

    // Remove the first and last character
    // This prevents matching the original string itself
    string ss = doubled.substr(1, 2 * s.size() - 2);

    // If original string exists in this substring, it is repeated
    return ss.find(s) != string::npos;
}

