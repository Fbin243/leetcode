class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int size = nums.size();
        if(size == 3) return nums[0]*nums[1]*nums[2];
        // sort(nums.begin(), nums.end());
        // return max(nums[0]*nums[1]*nums[size-1], nums[size-1]*nums[size-2]*nums[size-3]);
        int max1,max2, max3, min1, min2;
        max1 = max2 = max3 = INT_MIN;
        min1 = min2 = INT_MAX;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] > max1) {
                max3 = max2;
                max2 = max1;
                max1 = nums[i];
            } else if(nums[i] > max2) {
                max3 = max2;
                max2 = nums[i];
            } else if(nums[i] > max3) max3 = nums[i];
            
            if(nums[i] < min1) {
                min2 = min1;
                min1 = nums[i];
            } else if(nums[i] < min2) {
                min2 = nums[i];
            }
        }
        return max(min1*min2*max1, max1*max2*max3);
    }
};