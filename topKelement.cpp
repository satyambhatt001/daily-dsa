#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> freq;

        // Count frequency
        for (int x : nums) {
            freq[x]++;
        }

        // Store as {frequency, number}
        vector<pair<int,int>> v;
        for (auto it : freq) {
            v.push_back({it.second, it.first});
        }

        // Sort in descending order of frequency
        sort(v.rbegin(), v.rend());

        // Pick top k
        vector<int> res;
        for (int i = 0; i < k; i++) {
            res.push_back(v[i].second);
        }

        return res;
    }
};
