class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
        // This vector will store the maximum of each sliding window
        vector<int> result;

        // n = total number of elements in the array
        int n = nums.size();

        // We slide the window from left to right
        // Last starting index = n - k
        // Because window size is k
        for (int i = 0; i <= n - k; i++) {

            // Assume the first element of the window is the maximum
            // Window starts at index i
            int maxi = nums[i];

            // Now check all elements inside this window
            // Window range: i → i + k - 1
            for (int j = i; j < i + k; j++) {

                // Compare current element with maxi
                // Update maxi if nums[j] is larger
                maxi = max(maxi, nums[j]);
            }

            // After scanning the full window,
            // store the maximum value in result
            result.push_back(maxi);
        }

        // Return the list of window maximums
        return result;
    }
};

// 2nd approach

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
          int n = nums.size();
        vector<int> ans;
        deque<int> dq; 

        for (int i = 0; i < n; i++) {

           
            if (!dq.empty() && dq.front() <= i - k) {
                dq.pop_front();
            }

           
            while (!dq.empty() && nums[dq.back()] < nums[i]) {
                dq.pop_back();
            }

  
            dq.push_back(i);


            if (i >= k - 1) {
                ans.push_back(nums[dq.front()]);
            }
        }

        return ans;
    }
};
