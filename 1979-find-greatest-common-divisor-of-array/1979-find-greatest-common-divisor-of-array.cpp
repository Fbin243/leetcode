class Solution {
public:
    int gcd(int a, int b) {
        while(a != b) {
            if(a > b) a = a - b;
            else b = b - a;
        }
        return a;
    }
    int findGCD(vector<int>& nums) {
        int min = INT_MAX;
        int max = INT_MIN;
        for(int i = 0; i < nums.size(); i++) {
            if(min > nums[i]) min = nums[i];
            if(max < nums[i]) max = nums[i];
        }
        return gcd(max, min);
    }
};