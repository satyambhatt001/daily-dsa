class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());
        vector<int> v(s.begin(), s.end());
        sort(v.begin(), v.end());
        int ans = 1;
        for (int i = 0; i < v.size(); i++) {
            if (v[i] < 0) {
                continue;
            }
            if (v[i] == ans) {
                ans++;
            } else if (v[i] > ans) {
                return ans;
            }
        }
        return ans;
    }

};

//2nd 

#include <unordered_set>
using namespace std;

int solution(vector<int> &A) {
    unordered_set<int> s(A.begin(), A.end());

    int ans = 1;
    while (s.count(ans)) {
        ans++;
    }

    return ans;
};
