class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& a) {

        int n = a.size();
        int m = a[0].size();

        vector<int> ans;

        int top = 0;
        int bottom = n - 1;
        int left = 0;
        int right = m - 1;

        while (top <= bottom && left <= right) {

            // 1. Left to Right
            for (int j = left; j <= right; j++) {
                ans.push_back(a[top][j]);
            }
            top++;

            // 2. Top to Bottom
            for (int i = top; i <= bottom; i++) {
                ans.push_back(a[i][right]);
            }
            right--;

            // 3. Right to Left
            if (top <= bottom) {
                for (int j = right; j >= left; j--) {
                    ans.push_back(a[bottom][j]);
                }
                bottom--;
            }

            // 4. Bottom to Top
            if (left <= right) {
                for (int i = bottom; i >= top; i--) {
                    ans.push_back(a[i][left]);
                }
                left++;
            }
        }

        return ans;
    }
};
