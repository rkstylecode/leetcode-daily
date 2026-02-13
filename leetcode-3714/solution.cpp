class Solution {
public:
    int n;
    int single(string& s){
        int maxLen = 1;
        char currChar = 'x';

        int j = -1;
        for(int i=0; i<n; i++){
            if(s[i]==currChar){
                maxLen = max(maxLen, i-j);
            }
            else{
                currChar = s[i];
                j = i - 1;
            }
        }
        return maxLen;
    }

    int paired(char ch1, char ch2, string& s){
        unordered_map<int, int> mp;
        mp[0] = -1;

        int maxLen = 0, diff = 0;
        for(int i=0; i<n; i++){
            if(s[i]==ch1) diff++;
            else if(s[i]==ch2) diff--;
            else{
                diff = 0;
                mp.clear();
                mp[0] = i;
                continue;
            }

            if(mp.count(diff)){
                maxLen = max(maxLen, i - mp[diff]);
            }
            else mp[diff] = i;
        }
        return maxLen;
    }

    int triplet(string& s){
        unordered_map<string, int> mp;
        mp["0_0"] = -1;

        int maxLen = 0;
        int a = 0, b = 0, c = 0;

        for(int i=0; i<n; i++){
            if(s[i]=='a') a++;
            else if(s[i]=='b') b++;
            else c++;

            int diff1 = a - b;
            int diff2 = a - c;
            string key = to_string(diff1) + '_' + to_string(diff2);

            if(mp.count(key)){
                maxLen = max(maxLen, i - mp[key]);
            }
            else mp[key] = i;
        }
        return maxLen;
    }

    int longestBalanced(string s) {
        n = s.length();
        int maxLen = 0;

        maxLen = max(maxLen, single(s));

        maxLen = max(maxLen, paired('a', 'b', s));
        maxLen = max(maxLen, paired('b', 'c', s));
        maxLen = max(maxLen, paired('c', 'a', s));

        maxLen = max(maxLen, triplet(s));

        return maxLen;
    }
};