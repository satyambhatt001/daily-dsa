class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {

        int i = 0;
        int j = 0;

        while(i < nums1.size() && j < nums2.size()){

            if(nums1[i] == nums2[j]){
                return nums1[i];
            }

            else if(nums1[i] < nums2[j]){
                i++;
            }

            else{
                j++;
            }
        }

        return -1;
    }
};

//2nd

class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        set<int> st;
        set<int> st2;

        for (int x : nums1) {
            st.insert(x);
        }

        for (int x : nums2) {
            st2.insert(x);
        }
        unordered_map<int, int> mpp;

        for (int x : st) {
            mpp[x]++;
        }

        for (int x : st2) {
            mpp[x]++;
        }
        int mini;
        vector<int> ans;
        for (auto& p : mpp) {
            if (p.second >= 2) {
                ans.push_back(p.first);
            }
        }

        if(ans.empty()){
            return -1;
        }
        mini = *min_element(ans.begin(), ans.end());
        return mini;
    }
};
