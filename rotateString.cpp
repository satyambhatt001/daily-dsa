// Example 1:

// Input: s = "abcde", goal = "cdeab"
// Output: true
// Example 2:

// Input: s = "abcde", goal = "abced"
// Output: false


class Solution {
public:
    bool rotateString(string s, string goal) {
        int n=s.size();
        int n1=goal.size();
          if (n != n1){ 
            return false;
          }

    for (int i = 0; i < s.size(); i++) {
        rotate(s.begin(), s.begin() + 1, s.end());
        if (s == goal) 
        return true;
    }
    return false;
    }
};



//2nd approach
bool rotateString(string s, string goal) {
    if (s.length() != goal.length()) return false;
    string text = s + s;

    return kmpSearch(text, goal);
}

//3rd approach

class Solution {
public:
    bool rotateString(string s, string goal) {
        
        if (s.length() != goal.length())
            return false;


        string doubled = s + s;


        if (doubled.find(goal) != string::npos)
            return true;

        return false;
    }
};
