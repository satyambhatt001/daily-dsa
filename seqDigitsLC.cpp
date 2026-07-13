class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        //     vector<int> ans;
        //     for (int i = low; i <= high; i++) {
        //         string str = to_string(i);

        //         string seq = "";

        //         seq += str[0];
        //         for (int i = 0; i < str.size() - 1; i++) {
        //             if (str[i + 1] == str[i] + 1) {

        //                 seq += str[i + 1];
        //             } else {
        //                 break;
        //             }
        //         }

        //         if (seq == str)
        //             ans.push_back(stoi(seq));
        //     }
        //   return ans;
        vector<int> ans;
        for (int i = 1; i <= 9; ++i) {
            int num = i;
            for (int j = i + 1; j <= 9; ++j) {
                num = num * 10 + j;
                if (num >= low && num <= high)
                    ans.push_back(num);
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};
