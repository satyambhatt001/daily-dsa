class Solution {
public:
    int reverseDegree(string s) {
        int sum=0;
        for(int i=0;i<s.size();i++){
          
               int ascii='z'-s[i]+1;
              int  pro =ascii*(i+1);
               sum +=pro;
        }
        return sum;
    }
};
