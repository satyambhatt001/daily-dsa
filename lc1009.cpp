class Solution {
public:
    int bitwiseComplement(int n) {
        if(n==0) return 1;
        string bin=bitset<32>(n).to_string();
         int pos = bin.find('1'); 
        for(int i=pos;i<bin.size();i++){
            if(bin[i]=='0'){
                bin[i]='1';
            } else bin[i]='0';
        }
         bitset<32> b(bin); 
         int x = b.to_ullong();

         return x;
    }
};
