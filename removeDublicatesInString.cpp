class Solution {
  public:
    string removeDuplicates(string &s) {
        
        unordered_set<char> st;
        string ans = "";
        
        for(char c : s) {
            if(st.count(c) == 0) {
                ans += c;
                st.insert(c);
            }
        }
        
        return ans;
    }
};
