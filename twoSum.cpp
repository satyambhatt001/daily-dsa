/* vector<int> twoSum(vector<int>&nums,int target){
    unordered_map<int,int>map;
    for(int i=0;i<nums.size();i++){
        intn complement=target-nums[i];
        if(map.find(complement)!=map.end()){
            return {map[complement],i};
        }
        map[nums[i]]=i;

    }
    return {};
} */

//best optimality

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> mp;
    for (int i = 0; i < (int)nums.size(); i++) {
        int complement = target - nums[i];
        if (mp.find(complement) != mp.end()) {
            return {mp[complement], i};
        }
        mp[nums[i]] = i;
    }
    return {};
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, target;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];
    cin >> target;

    vector<int> ans = twoSum(nums, target);
    if (!ans.empty()) {
        cout << ans[0] << " " << ans[1] << "\n";
    } else {
        cout << -1 << "\n"; 
    }

    return 0;
}

//2 pointer approach

#include <bits/stdc++.h>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    int n = nums.size();
    vector<pair<int,int>> arr;
    for (int i = 0; i < n; i++) arr.push_back({nums[i], i});

    sort(arr.begin(), arr.end());

    int left = 0, right = n - 1;
    while (left < right) {
        int sum = arr[left].first + arr[right].first;
        if (sum == target) return {arr[left].second, arr[right].second};
        else if (sum < target) left++;
        else right--;
    }
    return {};
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, target;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];
    cin >> target;

    vector<int> ans = twoSum(nums, target);
    if (!ans.empty()) cout << ans[0] << " " << ans[1] << "\n";
    else cout << -1 << "\n";

    return 0;
}
