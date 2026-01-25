class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        sort(begin(nums), end(nums), greater<int>());

        int diff = INT_MAX;
        int n = nums.size();
        
        for(int i=0; i<=n-k; i++){
            diff = min(diff, nums[i]-nums[i+k-1]);
        }
        return diff;
    }
};