class Solution {
public:
    int firstUniqChar(string s) {
  
        unordered_map<char, int> countMap; 
       
        for (char c : s) {
            countMap[c]++;
        }
        
        for (int i = 0; i < s.size(); i++) {
            if (countMap[s[i]] == 1) {
                return i;
            }
        }
        
        return -1; 
    }
};
