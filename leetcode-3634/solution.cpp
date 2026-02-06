class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        sort(begin(nums), end(nums));

        int ans = INT_MAX;

        int n = nums.size();
        for(int i=0; i<n; i++){
            long long maxVal = 1LL*k*nums[i];
            int lastIdx = upper_bound(begin(nums), end(nums), maxVal) - begin(nums);

            int elementsRemoved = i + n - lastIdx;
            ans = min(ans, elementsRemoved);
        }
        return ans;
    }
};