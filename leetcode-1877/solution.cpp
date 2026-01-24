class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(begin(nums), end(nums));

        int maxSum = 0;
        int n = nums.size();
        int i = 0, j = n-1;

        while(i<j){
            maxSum = max(maxSum, nums[i]+nums[j]);
            i++, j--;
        }
        return maxSum;
    }
};