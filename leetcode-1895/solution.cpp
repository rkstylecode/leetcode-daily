class Solution {
public:
    int solve(int row, int col, int m, int n, vector<vector<int>>& grid, vector<vector<int>>& rowPrefSum, vector<vector<int>>& colPrefSum){
        int sqLen = 1;
        int kMax = min(m-row, n-col) - 1;

        for(int k=1; k<=kMax; k++){
            bool flag = true;
            int sum = rowPrefSum[row][col+k] - (col>0 ? rowPrefSum[row][col-1] : 0);

            for(int i=row; i<=row+k; i++){
                int rowSum = rowPrefSum[i][col+k] - (col>0 ? rowPrefSum[i][col-1] : 0);

                if(rowSum!=sum){
                    flag = false;
                    break;
                }
            }
            if(!flag) continue;

            for(int j=col; j<=col+k; j++){
                int colSum = colPrefSum[row+k][j] - (row>0 ? colPrefSum[row-1][j] : 0);

                if(colSum!=sum){
                    flag = false;
                    break;
                }
            }
            if(!flag) continue;

            int diagSum = 0;
            for(int i=0; i<=k; i++){
                diagSum += grid[row+i][col+i];
            }
            if(diagSum!=sum) continue;

            int antiDiagSum = 0;
            for(int i=0; i<=k; i++){
                antiDiagSum += grid[row+k-i][col+i];
            }
            if(antiDiagSum!=sum) continue;

            sqLen = k + 1;
        }
        return sqLen;
    }

    int largestMagicSquare(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> rowPrefSum(m, vector<int>(n)), colPrefSum(m, vector<int>(n));

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                rowPrefSum[i][j] += grid[i][j] + (j>0 ? rowPrefSum[i][j-1] : 0);
            }
        }

        for(int j=0; j<n; j++){
            for(int i=0; i<m; i++){
                colPrefSum[i][j] += grid[i][j] + (i>0 ? colPrefSum[i-1][j] : 0);
            }
        }

        int ans = 1;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                ans = max(ans, solve(i, j, m, n, grid, rowPrefSum, colPrefSum));
            }
        }
        return ans;
    }
};