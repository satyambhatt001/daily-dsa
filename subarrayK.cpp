// Given an integer array nums and an integer k,
// find the maximum sum of any contiguous subarray of size k.

// Return the maximum sum.

// If k > nums.length, return -1.

// Example 1
// Input: nums = [2,1,5,1,3,2], k = 3
// Output: 9

// Explanation:

// [2,1,5] = 8
// [1,5,1] = 7
// [5,1,3] = 9  ← max
// [1,3,2] = 6




int maxSumBF(vector<int>& a)
{
    int n = a.size();
    int k = 3;

    int maxi = INT_MIN;

    for(int i = 0; i <= n - k; i++)
    {
        int sum = 0;

        for(int j = i; j < i + k; j++)
        {
            sum += a[j];
        }

        maxi = max(maxi, sum);
    }

    return maxi;
}

//sliding window

int maxSumSW(vector<int>& a, int k)
{
    int n = a.size();

    if(k > n) return -1;

    int sum = 0;

    // first window
    for(int i = 0; i < k; i++)
        sum += a[i];

    int maxi = sum;

    // slide window
    for(int i = k; i < n; i++)
    {
        sum += a[i];
        sum -= a[i - k];

        maxi = max(maxi, sum);
    }

    return maxi;
}
