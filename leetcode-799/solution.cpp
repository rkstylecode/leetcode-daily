class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<vector<double>> glass(100, vector<double>(100));
        glass[0][0] = poured;

        for(int i=1; i<100; i++){
            bool overflowPossible = false;

            for(int j=0; j<=i; j++){
                if(j-1>=0 && glass[i-1][j-1]>1){
                    double overflow = glass[i-1][j-1] - 1;
                    glass[i][j] += overflow/2;
                }
                if(glass[i-1][j]>1){
                    double overflow = glass[i-1][j] - 1;
                    glass[i][j] += overflow/2;
                }
                
                if(!overflowPossible && glass[i][j]>1){
                    overflowPossible = true;
                }
            }

            if(!overflowPossible){
                break;
            }
        }

        double val = glass[query_row][query_glass];
        return val>1 ? 1 : val;
    }
};