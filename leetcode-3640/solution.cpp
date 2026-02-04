class Solution {
public:
    typedef long long ll;
    int n;
    ll solve(int idx, int phase, vector<int>& nums, vector<vector<ll>>& dp){
        if(idx==n){
            return phase==3 ? 0LL : LLONG_MIN/2;
        }

        if(dp[idx][phase]!=LLONG_MIN){
            return dp[idx][phase];
        }

        ll skip = LLONG_MIN/2;
        ll take = LLONG_MIN/2;

        if(phase==0){
            skip = solve(idx+1, 0, nums, dp);
        }
        if(phase==3){
            take = nums[idx];
        }

        if(idx+1<n){
            if(phase==0 && nums[idx+1]>nums[idx]){
                take = max(take, nums[idx] + solve(idx+1, 1, nums, dp));
            }
            else if(phase==1){
                if(nums[idx+1]>nums[idx]){
                    take = max(take, nums[idx] + solve(idx+1, 1, nums, dp));
                }
                else if(nums[idx+1]<nums[idx]){
                    take = max(take, nums[idx] + solve(idx+1, 2, nums, dp));
                }
            }
            else if(phase==2){
                if(nums[idx+1]<nums[idx]){
                    take = max(take, nums[idx] + solve(idx+1, 2, nums, dp));
                }
                else if(nums[idx+1]>nums[idx]){
                    take = max(take, nums[idx] + solve(idx+1, 3, nums, dp));
                }
            }
            else if(phase==3 && nums[idx+1]>nums[idx]){
                take = max(take, nums[idx] + solve(idx+1, 3, nums, dp));
            }
        }
        return dp[idx][phase] = max(skip, take);
    }

    long long maxSumTrionic(vector<int>& nums) {
        n = nums.size();
        vector<vector<ll>> dp(n, vector<ll>(4, LLONG_MIN));

        return solve(0, 0, nums, dp);    
    }
};