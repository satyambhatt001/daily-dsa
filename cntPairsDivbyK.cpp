class Solution {
  public:
    int countKdivPairs(vector<int>& arr, int k) {
        // code here
        // int cnt=0;
        // for(int i=0;i<arr.size();i++){
        //     for(int j=i+1;j<arr.size();j++){
        //         if((arr[i]+arr[j])%k==0){
        //             cnt++;
        //         }
        //     }
        // }
        // return cnt;
        // int i=0;
        // int j=arr.size()-1;
        // int cnt=0;
        
        // while(i<j){
        //     if((arr[i]+arr[j])%k){
        //         cnt++;
        //     }
        //     i++;
        //     j--;
        // }
        // return cnt;
         vector<int> freq(k, 0);
    int count = 0;

    for (int x : arr) {
        int rem = x % k;
        int need = (k - rem) % k;

        count += freq[need];

        freq[rem]++;
    }

    return count;
        
    }
};
