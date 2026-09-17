class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
    //     int n=nums.size();
    //     for(int i=0;i<n;i++){
    //         if(nums[i]<0){
    //             swap(nums[i],nums[i+1]);
    //         }
    //         if(nums[i]>0 && nums[i+1]>0){
    //             swap(nums[i+1],nums[i+2]);
    //         }
    //         if(nums[i]<0 && nums[i+1]<0){
    //             swap(nums[i+1],nums[i+2]);
    //         }else{
    //             break;
    //         }
    //     }
    //     return nums;
    // }
    int posIndex=0,negIndex=1;
    int n=nums.size();
    vector<int> result(n);
    for(int i=0;i<n;i++){
        if(nums[i]>0){
            result[posIndex]=nums[i];
            posIndex +=2;
        }else {
            result[negIndex]=nums[i];
            negIndex +=2;
        }
    }
    return result;

    }
};
