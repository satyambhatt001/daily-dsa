//1st approach
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int smallest = 1;

        for (int x : nums) {
            if (x == smallest) {
                smallest++;
            }
        }

        return smallest;
    }
};

//2nd approach

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());

        int smallest = 1;

        while (true) {
            if (s.find(smallest) == s.end())
                return smallest;

            smallest++;
        }
    }
};

//3rd accepted in interviews

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();

        for (int i = 0; i < n; i++) {

            while (nums[i] >= 1 && nums[i] <= n &&
                   nums[i] != nums[nums[i] - 1]) {

                swap(nums[i], nums[nums[i] - 1]);
            }
        }

        for (int i = 0; i < n; i++) {
            if (nums[i] != i + 1)
                return i + 1;
        }

        return n + 1;
    }
};
