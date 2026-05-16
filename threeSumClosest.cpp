class Solution {
public:
    vector<int> threeSumClosest(vector<int>& nums, int target) {
        
        int n = nums.size();
        
        // store value + original index
        vector<pair<int,int>> a;
        for (int i = 0; i < n; i++) {
            a.push_back({nums[i], i});
        }
        
        sort(a.begin(), a.end());
        
        int bestSum = a[0].first + a[1].first + a[2].first;
        
        vector<int> ans = {a[0].second, a[1].second, a[2].second};
        
        for (int i = 0; i < n - 2; i++) {
            
            int l = i + 1;
            int r = n - 1;
            
            while (l < r) {
                
                int sum = a[i].first + a[l].first + a[r].first;
                
                if (abs(sum - target) < abs(bestSum - target)) {
                    bestSum = sum;
                    ans = {a[i].second, a[l].second, a[r].second};
                }
                
                if (sum < target) {
                    l++;
                }
                else if (sum > target) {
                    r--;
                }
                else {
                    return {a[i].second, a[l].second, a[r].second};
                }
            }
        }
        
        return ans;
    }
};
