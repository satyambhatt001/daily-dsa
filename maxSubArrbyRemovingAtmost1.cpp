class Solution {
  public:
    int maxSumSubarray(vector<int>& arr) {
        // code here
        int n = arr.size();
        int keep = arr[0];
    
        int del = 0;

        int ans = arr[0];

        for (int i = 1; i < n; i++) {
            int prevKeep = keep;

           
            keep = max(arr[i], keep + arr[i]);

         
            del = max(del + arr[i], prevKeep);

            ans = max(ans, max(keep, del));
        }

        return ans;
    }
};
