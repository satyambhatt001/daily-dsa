#include <stack>
#include <string>
using namespace std;

// Function to check if the input string 's' has valid parentheses, brackets, and braces
bool isValid(string &s) {
    stack<char> st; // Stack to keep track of opening brackets

    // Traverse each character in the string
    for(int i = 0; i < s.length(); i++) {
        char ch = s[i]; // Current character

        // If the character is an opening bracket, push it onto the stack
        if(ch == '(' || ch == '{' || ch == '[') {
            st.push(ch);
        } else {
            // If the stack is empty, it means there is no matching opening bracket
            if(st.empty()) {
                return false; // Invalid string
            }

            char top = st.top(); // Get the top element of the stack (last unmatched opening bracket)

            // Check if the current closing bracket matches the top opening bracket
            // Mistake in your original code: 
            // (ch=='}' && top!='{}') is wrong, should be top != '{'
            // Similarly, (ch=='[' && top!=']') is wrong, should be (ch==']' && top != '[')
            if( (ch == ')' && top != '(') ||
                (ch == '}' && top != '{') ||
                (ch == ']' && top != '[') ) {
                return false; // Mismatch found
            }

            // Pop the matched opening bracket from the stack
            st.pop(); 
        }
    }

    // If stack is empty, all brackets were matched correctly
    return st.empty(); // True if valid, false if there are unmatched opening brackets
}


//2nd approach using ascii



bool isValid(string s) {
    stack<int> st;   // store ASCII numbers

    // ASCII reference:
    // ( = 40   ) = 41
    // [ = 91   ] = 93
    // { = 123  } = 125

    for (char c : s) {
        int x = (int)c;   // ASCII value of the character

        // opening brackets
        if (x == 40    || x == 91   || x == 123) 
        {
            st.push(x);
        } 
        else {
            if (st.empty()) return false;

            int top = st.top();
            st.pop();

            int diff = x - top;

            // ASCII only rule:
            // ')' - '(' = 1
            // ']' - '[' = 2
            // '}' - '{' = 2
            if (diff != 1 && diff != 2)
                return false;
        }
    }

    return st.empty();
}
