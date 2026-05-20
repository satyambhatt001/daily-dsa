class Solution {
  public:
    bool isProduct(vector<int>& arr, long long target) {
        // code here
         sort(arr.begin(), arr.end());

        int i = 0;
        int j = arr.size() - 1;

        while (i < j) {

            long long product = 1LL * arr[i] * arr[j];

            if (product == target) {
                return true;
            }
            else if (product < target) {
                i++;
            }
            else {
                j--;
            }
        }

        return false;
    }
};
