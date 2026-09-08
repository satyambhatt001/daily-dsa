#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main() {
    string s1, s2;
    cin >> s1 >> s2;

    if (s1.size() != s2.size()) {
        cout << 0;
        return 0;
    }

    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());

    if (s1 != s2) {
        cout << 0;
        return 0;
    }

    int n = s1.size();

    // Convert n to binary
    string binary = "";

    while (n > 0) {
        binary += (n % 2) + '0';
        n /= 2;
    }

    reverse(binary.begin(), binary.end());

    cout << binary;

    return 0;
}
