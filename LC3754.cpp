class Solution {
public:
    long long sumAndMultiply(int n) {
        int sum=0;
        vector<int>v;
          long long ans=0;
        while(n>0){
            int rem=n%10;
            if(rem!=0){
             v.push_back(rem);
            }
            sum +=rem;
            n /=10;
        }
        reverse(v.begin(),v.end());
        long long num = 0;
        for (int x : v) {
      num = num * 10 + x;
      }
        ans=1LL*sum*num;


        return ans;

    }
};
