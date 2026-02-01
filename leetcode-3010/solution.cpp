class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int minSum = INT_MAX;

        int n = nums.size();
        for(int i=0; i<n-2; i++){
            int sum1 = nums[0];

            for(int j=i+1; j<n-1; j++){
                int sum2 = nums[i+1];
                int sum3 = nums[j+1];

                minSum = min(minSum, sum1+sum2+sum3);
            }
        }
        return minSum;
    }
};