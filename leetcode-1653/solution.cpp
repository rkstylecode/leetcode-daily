class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.length();
        vector<int> aCount(n), bCount(n);

        for(int i=0; i<n; i++){
            aCount[i] += i>0 ? aCount[i-1] : 0;
            aCount[i] += s[i]=='a' ? 1 : 0;
            
            bCount[i] += i>0 ? bCount[i-1] : 0;
            bCount[i] += s[i]=='b' ? 1 : 0;
        }

        int ans = INT_MAX;
        for(int i=0; i<n; i++){
            int currCount = (i>0 ? bCount[i-1] : 0) + (aCount[n-1] - aCount[i]);
            ans = min(ans, currCount);
        }
        return ans;
    }
};