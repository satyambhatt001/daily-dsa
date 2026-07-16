class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int maxi=nums[0];
        vector<int>v;
        int prefixGcd;
        for(int i=0;i<nums.size();i++){
             if(nums[i]>maxi){
            maxi=nums[i];
           }
           prefixGcd=gcd(maxi,nums[i]);
           v.push_back(prefixGcd);
          
        }
        sort(v.begin(),v.end());
       
        long long sum=0;
        int i=0, j=v.size()-1;
        while(i<j){
            int g=gcd(v[i],v[j]);
            sum +=g;
            i++;
            j--;
        }
        
        return sum;

    }
};
