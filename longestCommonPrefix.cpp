// Function to find the Longest Common Prefix (LCP) among strings
string longestCommonPrefix(vector<string> &str) {
    // If the input list is empty, return an empty string
    if (str.empty())
        return "";

    // Start with the first string as the initial prefix
    string prefix = str[0];

    // Compare prefix with each string one by one
    for (int i = 1; i < str.size(); i++) {
        // While current string does not start with the current prefix
        // keep reducing the prefix from the end
        while (str[i].find(prefix) != 0) {
            prefix = prefix.substr(0, prefix.size() - 1);

            // If prefix becomes empty, no common prefix exists
            if (prefix.empty())
                return "";
        }
    }

    // Return the final longest common prefix
    return prefix;
}
