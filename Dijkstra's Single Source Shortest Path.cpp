#define ll long long
ll MAX = 1e15;
// adj => u -> (v, cost)
// pq => return minCost node each time
vector<ll> dijk(int src, vector<vector<pair<ll, ll>>> &adj){
    ll N = adj.size();
    priority_queue<pair<ll,ll> , vector<pair<ll,ll>> , greater<pair<ll,ll>>> pq;

    vector<ll> minCost(N, MAX);
    pq.push({0, src});
    minCost[src] = 0;

    while(!pq.empty()){
        auto [cost, u] = pq.top();
        pq.pop();
        if(cost > minCost[u]) continue;
        for(auto &i : adj[u]){
            auto [neiCost, v] = i;
            if(cost+neiCost < minCost[v]){
                minCost[v] = cost+neiCost;
                pq.push({minCost[v], v});
            }
        }    
    }

    return minCost;
}
