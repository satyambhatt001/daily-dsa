class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        //  unordered_set<char> st;

        // int i = 0;          // left pointer
        // int maxLen = 0;

        // for (int j = 0; j < s.size(); j++) {   // right pointer

        //     while (st.count(s[j])) {   // duplicate found
        //         st.erase(s[i]);        // remove from left
        //         i++;                   // move left pointer
        //     }

        //     st.insert(s[j]);           // add current character

        //     maxLen = max(maxLen, j - i + 1);   // update answer
        // }

        // return maxLen;
      
        int maxLen=0;
        int n=s.size();
        for(int i=0;i<n;i++){
              set<char>st;
            for( int j=i;j<n;j++){
                if(st.count(s[j])){
                    break;
                }
                st.insert(s[j]);
                 maxLen=max(maxLen,j-i+1);
            }
           
        }
        return maxLen;
    }
};
