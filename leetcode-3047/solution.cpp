class Solution {
public:
    long long largestSquareArea(vector<vector<int>>& bottomLeft, vector<vector<int>>& topRight){
        long long area = 0LL;

        int n = bottomLeft.size();
        for(int i=0; i<n; i++){
            int xLeft_i = bottomLeft[i][0];
            int yBottom_i = bottomLeft[i][1];
            int xRight_i = topRight[i][0];
            int yTop_i = topRight[i][1];

            for(int j=i+1; j<n; j++){
                int xLeft_j = bottomLeft[j][0];
                int yBottom_j = bottomLeft[j][1];
                int xRight_j = topRight[j][0];
                int yTop_j = topRight[j][1];

                int overlapWidth = max(0, min(xRight_i, xRight_j) - max(xLeft_i, xLeft_j));
                int overlapHeight = max(0, min(yTop_i, yTop_j) - max(yBottom_i, yBottom_j));

                int sideLen = min(overlapWidth, overlapHeight);
                area = max(area, 1LL*sideLen*sideLen);
            }
        }
        return area;
    }
};