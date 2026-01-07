//1st approach

double findMedianSortedArrays(vector<int>& a, vector<int>& b) {
    // push every element of b into a
    for(int x : b) {
        a.push_back(x);
    }

    // sort the merged array
    sort(a.begin(), a.end());

    int n = a.size();

    // odd size
    if(n % 2 == 1) {
        return a[n / 2];
    }

    // even size
    int mid1 = n / 2;
    int mid2 = mid1 - 1;

    return (a[mid1] + a[mid2]) / 2.0;
}


//2nd approach

class Solution {
public:
    double findMedianSortedArrays(vector<int>& A, vector<int>& B) {

        // Always binary search on the smaller array
        if (A.size() > B.size())
            return findMedianSortedArrays(B, A);

        int n = A.size();
        int m = B.size();

        int low = 0;
        int high = n;

        while (low <= high) {

            // cut positions
            int cut1 = low + (high - low) / 2;
            int cut2 = (n + m + 1) / 2 - cut1;

            // Left and right values around cuts
            int L1 = (cut1 == 0) ? INT_MIN : A[cut1 - 1];
            int R1 = (cut1 == n) ? INT_MAX : A[cut1];

            int L2 = (cut2 == 0) ? INT_MIN : B[cut2 - 1];
            int R2 = (cut2 == m) ? INT_MAX : B[cut2];

            // Correct partition found
            if (L1 <= R2 && L2 <= R1) {

                // total odd → max of left side
                if ((n + m) % 2 == 1)
                    return max(L1, L2);

                // total even → avg of middle two
                return (max(L1, L2) + min(R1, R2)) / 2.0;
            }

            // Move left in A
            else if (L1 > R2)
                high = cut1 - 1;

            // Move right in A
            else
                low = cut1 + 1;
        }

        return 0.0; // not reached
    }
};
