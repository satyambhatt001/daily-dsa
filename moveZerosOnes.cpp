void segregate0and1(vector<int>& arr) {
    int left = 0;
    int right = arr.size() - 1;

    while (left < right) {
        if (arr[left] == 0) {
            left++;
        }
        else if (arr[right] == 1) {
            right--;
        }
        else {
            swap(arr[left], arr[right]);
            left++;
            right--;
        }
    }
}
// 2nd approach
#include <vector>
using namespace std;

void segregate0and1(vector<int>& arr) {
    vector<int> vectorZero;
    vector<int> vectorOne;

    for (int num : arr) {
        if (num == 0)
            vectorZero.push_back(num);
        else
            vectorOne.push_back(num);
    }

    // merge using inbuilt function
    vectorZero.insert(vectorZero.end(), vectorOne.begin(), vectorOne.end());

    arr = vectorZero; // copy back
}
