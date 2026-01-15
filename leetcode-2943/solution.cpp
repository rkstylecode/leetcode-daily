class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        sort(begin(hBars), end(hBars));
        sort(begin(vBars), end(vBars));

        int maxHorizontalBars = 0;
        int maxVerticalBars = 0;
        int hCount = 0, vCount = 0;
        
        int h = hBars.size();
        for(int i=0; i<h; i++){
            if(i==0 || hBars[i]==hBars[i-1]+1){
                hCount++;
                maxHorizontalBars = max(maxHorizontalBars, hCount);
            }
            else{
                hCount = 1;
            }
        }

        int v = vBars.size();
        for(int i=0; i<v; i++){
            if(i==0 || vBars[i]==vBars[i-1]+1){
                vCount++;
                maxVerticalBars = max(maxVerticalBars, vCount);
            }
            else{
                vCount = 1;
            }
        }

        int sqLen = min(maxHorizontalBars, maxVerticalBars) + 1;
        return sqLen*sqLen;
    }
};