class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int, int>>> adj(n);
        vector<int> cost(n, INT_MAX);
        cost[0] = 0;

        for(auto &e: edges){
            auto u = e[0];
            auto v = e[1];
            auto w = e[2];

            adj[u].push_back({v, w});
            adj[v].push_back({u, 2*w});
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        pq.push({0, 0});

        while(!pq.empty()){
            auto [currCost, currNode] = pq.top();
            pq.pop();

            for(auto &next: adj[currNode]){
                auto [nextNode, nextCost] = next;
                int totalCost = currCost + nextCost;

                if(totalCost<cost[nextNode]){
                    cost[nextNode] = totalCost;
                    pq.push({totalCost, nextNode});
                }
            }
        }
        return cost[n-1]==INT_MAX ? -1 : cost[n-1];
    }
};