class Solution {
public:
    int longestBalanced(string s) {
        int maxLen = 0;

        int n = s.length();
        for(int i=0; i<n; i++){
            unordered_map<char, int> alpha;

            for(int j=i; j<n; j++){
                alpha[s[j]-'a']++;

                bool balanced = true;
                int prevFreq = -1;

                for(auto it: alpha){
                    auto currFreq = it.second;

                    if(prevFreq!=-1 && currFreq!=prevFreq){
                        balanced = false;
                        break;
                    }
                    prevFreq = currFreq;
                }

                if(balanced){
                    maxLen = max(maxLen, j-i+1);
                }
            }
        }
        return maxLen;
    }
};