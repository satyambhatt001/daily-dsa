class Solution {
public:

    int minToggle(vector<int>& arr) {

        int n = arr.size();

        int totalZero = 0;

        for(int x : arr){

            if(x == 0){
                totalZero++;
            }
        }

        int leftOne = 0;
        int rightZero = totalZero;

        // case: all 1s
        int ans = rightZero;

        for(int i = 0; i < n; i++){

            if(arr[i] == 1){
                leftOne++;
            }
            else{
                rightZero--;
            }

            ans = min(ans, leftOne + rightZero);
        }

        return ans;
    }
};
