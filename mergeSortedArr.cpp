vector<int> merge(vector<int>& arr1, vector<int>& arr2) {
    int i = 0, j = 0, k = 0;       // i -> index for arr1, j -> index for arr2, k -> index for merged array
    int n1 = arr1.size();          // size of first array
    int n2 = arr2.size();          // size of second array
    vector<int> merged(n1 + n2);   // create merged array of size n1+n2

    // Merge elements until we reach the end of either array
    while (i < n1 && j < n2) {
        if (arr1[i] < arr2[j]) {   // choose smaller element
            merged[k] = arr1[i];
            i++;                    // move index i forward
        } else {
            merged[k] = arr2[j];    // take element from arr2
            j++;                    // move index j forward
        }
        k++;                        // move merged array index forward
    }

    // Copy remaining elements of arr1 (if any)
    while (i < n1) {
        merged[k] = arr1[i];
        i++;
        k++;
    }

    // Copy remaining elements of arr2 (if any)
    while (j < n2) {
        merged[k] = arr2[j];
        j++;
        k++;
    }

    return merged;   // return the merged sorted array
}
