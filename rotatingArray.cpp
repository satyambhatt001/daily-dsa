#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> arr = {8, 3, 1, 2};
    int n = arr.size();

    int k = 1;              // number of rotations
    bool clockwise = true; // true → clockwise, false → anti-clockwise

    k = k % n;

    if (clockwise) {
        // CLOCKWISE (RIGHT ROTATION)
        reverse(arr.begin(), arr.end());
        reverse(arr.begin(), arr.begin() + k);
        reverse(arr.begin() + k, arr.end());
    } else {
        // ANTI-CLOCKWISE (LEFT ROTATION)
        reverse(arr.begin(), arr.begin() + k);
        reverse(arr.begin() + k, arr.end());
        reverse(arr.begin(), arr.end());
    }

    for (int x : arr)
        cout << x << " ";
}
