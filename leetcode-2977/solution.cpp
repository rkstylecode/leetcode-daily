class Solution {
public:
    int n;
    typedef long long ll;

    ll dijkstraAlgo(string& src, string& dest, unordered_map<string, vector<pair<string, ll>>>& adj, unordered_map<string, unordered_map<string, ll>>& minCost){
        if(minCost[src].count(dest)){
            return minCost[src][dest];
        }
        
        unordered_map<string, ll> effectiveCost;
        effectiveCost[src] = 0LL;
        effectiveCost[dest] = LLONG_MAX;

        priority_queue<pair<ll, string>, vector<pair<ll, string>>, greater<>> pq;
        pq.push({0LL, src});

        while(!pq.empty()){
            auto [currCost, currNode] = pq.top();
            pq.pop();

            for(auto &next: adj[currNode]){
                auto [nextNode, nextCost] = next;
                ll totalCost = currCost + nextCost;

                if(!effectiveCost.count(nextNode) || totalCost < effectiveCost[nextNode]){
                    effectiveCost[nextNode] = totalCost;
                    pq.push({totalCost, nextNode});
                }
            }
        }
        return minCost[src][dest] = effectiveCost[dest];
    }

    ll solve(int idx, string& source, string& target, unordered_map<string, vector<pair<string, ll>>>& adj, unordered_map<string, unordered_map<string, ll>>& minCost, set<int>& validLen, vector<ll>& dp){
        if(idx>=n) return 0LL;
        if(dp[idx]!=-1) return dp[idx];

        ll cost = LLONG_MAX;

        if(source[idx]==target[idx]){
            cost = solve(idx+1, source, target, adj, minCost, validLen, dp);
        }

        for(auto &len: validLen){
            if(idx+len>n) break;

            string sourceSub = source.substr(idx, len);
            string targetSub = target.substr(idx, len);

            if(!adj.count(sourceSub)){
                continue;
            }

            ll temp1 = dijkstraAlgo(sourceSub, targetSub, adj, minCost);
            ll temp2 = solve(idx+len, source, target, adj, minCost, validLen, dp);

            if(temp1!=LLONG_MAX && temp2!=LLONG_MAX){
                cost = min(cost, temp1 + temp2);    
            }
        }
        return dp[idx] = cost;
    }

    long long minimumCost(string source, string target, vector<string>& original, vector<string>& changed, vector<int>& cost) {
        unordered_map<string, vector<pair<string, ll>>> adj;
        unordered_map<string, unordered_map<string, ll>> minCost;
        set<int> validLen;

        int m = original.size();
        for(int i=0; i<m; i++){
            adj[original[i]].push_back({changed[i], cost[i]});
            validLen.insert(original[i].length());
        }

        n = source.length();
        vector<ll> dp(n, -1);
        ll ans = solve(0, source, target, adj, minCost, validLen, dp);

        return ans==LLONG_MAX ? -1 : ans;
    }
};