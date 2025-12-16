//Kaden's Algo

 /* int maxSubarray(vector<int>&nums){
    int maxSum=nums[0],currSum=nums[0];
    int n=nums.size();

    for(int i=0;i<n;i++){
        currSum=max(currSum,currSum+nums[i]);
        maxSum=max(maxSum,currSum);
    }
    return maxSum;
} */

#include <bits/stdc++.h>
using namespace std;

// Kadane's Algorithm: Find maximum subarray sum
int maxSubarray(vector<int>& nums) {
    int maxSum = nums[0];    // overall maximum sum
    int currSum = nums[0];   // current subarray sum
    int n = nums.size();

    for (int i = 1; i < n; i++) {  
        // Either start a new subarray at nums[i] OR extend the previous one
        currSum = max(nums[i], currSum + nums[i]);

        // Update global maximum
        maxSum = max(maxSum, currSum);
    }
    return maxSum;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cout << "Enter array size: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++) cin >> nums[i];

    int ans = maxSubarray(nums);
    cout << "Maximum subarray sum: " << ans << "\n";

    return 0;
}
