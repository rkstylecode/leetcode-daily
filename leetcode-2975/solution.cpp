class Solution {
public:
    const int MOD = 1e9 + 7;
    int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {
        hFences.push_back(1);
        hFences.push_back(m);
        vFences.push_back(1);
        vFences.push_back(n);

        int sideLen = 0;
        unordered_set<int> seen;

        int h = hFences.size();
        for(int i=0; i<h; i++){
            for(int j=i+1; j<h; j++){
                seen.insert(abs(hFences[j]-hFences[i]));
            }
        }

        int v = vFences.size();
        for(int i=0; i<v; i++){
            for(int j=i+1; j<v; j++){
                int diff = abs(vFences[j] - vFences[i]);

                if(seen.count(diff)){
                    sideLen = max(sideLen, diff);
                }
            }
        }
        return sideLen==0 ? -1 : (1LL*sideLen*sideLen)%MOD;
    }
};