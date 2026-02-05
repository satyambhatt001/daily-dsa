class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n=nums.size();
        vector<int> v;
        int i=0;
        while(i<n){
            int k;
            if(nums[i]==0){
                v.push_back(nums[i]);
            }
         else   if(nums[i]>0){
                 k=nums[i]%n;
                int newIdx = (i + k) % n;

                v.push_back(nums[newIdx]);
            }
            else if (nums[i]<0){
                k=abs(nums[i])%n;
                int newIdx=(i-k+n)%n;
                v.push_back(nums[newIdx]);
            }
            i++;
        }
        return v;
    }
};
