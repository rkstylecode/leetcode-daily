class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int n = nums.size();
        if(n==3) return 0;

        int i = 1;
        while(i<n){
            if(nums[i]>nums[i-1]) i++;
            else break;
        }
        if(i<2) return 0;

        int j = i;
        while(i<n){
            if(nums[i]<nums[i-1]) i++;
            else break;
        }
        if(i==j) return 0;

        int k = i;
        while(i<n){
            if(nums[i]>nums[i-1]) i++;
            else break;
        }
        if(i==k || i<n) return 0;
        return 1;
    }
};