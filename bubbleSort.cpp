// void bubbleSort(vector<int>&arr){
//     int n=arr.size();

//     for(int i=1;i<n;i++){
//         for(int j=0;j<n-i;j++){
//             if(arr[j]>arr[j+1]){
//                 swap(arr[j],arr[j+1]);
//             }
//         }
//     }
// }

#include <iostream>     // For input and output (cin, cout)
#include <vector>       // For using std::vector (dynamic array in C++)

using namespace std;    // To avoid writing std:: again and again

// =============================
// Function to perform Bubble Sort
// =============================
void bubbleSort(vector<int> &arr) {
    int n = arr.size();  // Get the number of elements in the vector

    // Outer loop -> runs n-1 times
    // After every pass, the largest element "bubbles up" to the end
    for (int i = 1; i < n; i++) {
        // Inner loop -> compares adjacent elements
        // (n-i) ensures that already sorted elements at the end are not touched
        for (int j = 0; j < n - i; j++) {
            // If the current element is greater than the next one, swap them
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

// =============================
// Helper function to print array
// =============================
void printArray(const vector<int> &arr) {
    for (int val : arr) {
        cout << val << " ";   // Print each element followed by space
    }
    cout << endl;
}

// =============================
// Main function (entry point of program)
// =============================
int main() {
    int n;

    // Ask user for number of elements
    cout << "Enter number of elements: ";
    cin >> n;

    // Create a vector of size n
    vector<int> arr(n);

    // Input array elements from user
    cout << "Enter " << n << " elements:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Show array before sorting
    cout << "\nArray before sorting: ";
    printArray(arr);

    // Call bubbleSort function
    bubbleSort(arr);

    // Show array after sorting
    cout << "Array after sorting: ";
    printArray(arr);

    return 0; // Program ends successfully
}
