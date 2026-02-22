class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int r=ransomNote.size();
        int m=magazine.size();
        if(r>m) return false;

        unordered_map<char,int>mpp;

        for(auto &c:ransomNote){
            mpp[c]++;
        }
        for(auto &c:magazine){
            mpp[c]--;
        }
        for(auto &p:mpp){
            if(p.second>0){
                return false;
            }
        }
        return true;
    }
};
