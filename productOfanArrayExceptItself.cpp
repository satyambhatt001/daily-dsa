#include <bits/stdc++.h>
using namespace std;

vector<int> productExceptSelf(vector<int>& nums) {
    int n = nums.size();

    vector<int> prefix(n, 1);  // prefix[i] = product of elements before i
    vector<int> suffix(n, 1);  // suffix[i] = product of elements after i
    vector<int> ans(n);        // final result

    // Build prefix product
    for (int i = 1; i < n; i++) {
        prefix[i] = prefix[i - 1] * nums[i - 1];
    }

    // Build suffix product
    for (int i = n - 2; i >= 0; i--) {
        suffix[i] = suffix[i + 1] * nums[i + 1];
    }

    // Build answer using prefix and suffix
    for (int i = 0; i < n; i++) {
        ans[i] = prefix[i] * suffix[i];
    }

    return ans;
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

    vector<int> ans = productExceptSelf(nums);

    cout << "Product of array except self: ";
    for (int x : ans) cout << x << " ";
    cout << "\n";

    return 0;
}
