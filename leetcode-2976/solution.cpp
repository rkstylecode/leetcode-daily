class Solution {
public:
    long long maxVal = LLONG_MAX;
    void floydWarshallAlgo(vector<vector<long long>>& minCost){
        for(int i=0; i<26; i++){
            minCost[i][i] = 0LL;
        }

        for(int via=0; via<26; via++){
            for(int i=0; i<26; i++){
                for(int j=0; j<26; j++){
                    if(minCost[i][via]==maxVal || minCost[via][j]==maxVal){
                        continue;
                    }
                    minCost[i][j] = min(minCost[i][j], minCost[i][via]+minCost[via][j]);
                }
            }
        }
    }

    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        vector<vector<long long>> minCost(26, vector<long long>(26, maxVal));

        int m = original.size();
        for(int i=0; i<m; i++){
            int from = original[i]-'a';
            int to = changed[i]-'a';

            minCost[from][to] = min(minCost[from][to], (long long)cost[i]);
        }
        floydWarshallAlgo(minCost);

        long long ans = 0LL;
        int n = source.length();
        
        for(int i=0; i<n; i++){
            int from = source[i]-'a';
            int to = target[i]-'a';

            if(minCost[from][to]==maxVal){
                return -1;
            }
            ans += minCost[from][to];
        }
        return ans;
    }
};