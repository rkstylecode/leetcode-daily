class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int maxLen = 0;

        int n = nums.size();
        for(int i=0; i<n; i++){
            unordered_set<int> even, odd;

            for(int j=i; j<n; j++){
                if(nums[j]%2){
                    odd.insert(nums[j]);
                }
                else{
                    even.insert(nums[j]);
                }

                if(even.size()==odd.size()){
                    maxLen = max(maxLen, j-i+1);
                }
            }
        }
        return maxLen;
    }
};