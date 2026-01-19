class Solution {
public:
    int m, n;
    bool isValid(int k, vector<vector<int>>& rowPrefSum, int threshold){
        for(int i=0; i<=m-k; i++){
            for(int j=0; j<=n-k; j++){
                int sum = 0;
                for(int row=i; row<i+k; row++){
                    sum += rowPrefSum[row][j+k-1] - (j>0 ? rowPrefSum[row][j-1] : 0);
                }

                if(sum<=threshold){
                    return 1;
                }
            }
        }
        return 0;
    }

    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        m = mat.size();
        n = mat[0].size();
        vector<vector<int>> rowPrefSum(m, vector<int>(n));

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                rowPrefSum[i][j] += mat[i][j] + (j>0 ? rowPrefSum[i][j-1] : 0);
            }
        }

        int ans = 0;
        int low = 1, high = min(m, n);

        while(low<=high){
            int mid = low + (high - low)/2;

            if(isValid(mid, rowPrefSum, threshold)){
                ans = mid;
                low = mid + 1;
            }
            else high = mid - 1;
        }
        return ans;
    }
};