class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        int ans = 0;
        while(nums.size()>1){
            int minSum = INT_MAX, deletedIdx = -1;
            bool isAscending = true;

            for(int i=0; i<nums.size()-1; i++){
                int sum = nums[i] + nums[i+1];

                if(sum<minSum){
                    minSum = sum;
                    deletedIdx = i + 1;
                }

                if(nums[i]>nums[i+1]){
                    isAscending = false;
                }
            }
            if(isAscending) break;

            ans++;
            nums[deletedIdx-1] = minSum;
            nums.erase(begin(nums) + deletedIdx);
        }
        return ans;
    }
};