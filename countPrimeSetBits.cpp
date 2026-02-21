class Solution {
public:
    int countPrimeSetBits(int left, int right) {
        vector<string> bin;
        for (int i = left; i <= right; i++) {
            bin.push_back(bitset<32>(i).to_string());
        }
        int cnt = 0;
        for (auto& b : bin) {
            int count1 = count(b.begin(), b.end(), '1');
            if (count1 == 2 || count1 == 3 || count1 == 5 ||
                       count1 == 7 || count1 == 11 || count1 == 13 ||
                       count1 == 17 || count1 == 19) {
                cnt++;
            }
        }
        return cnt;
    }
};
