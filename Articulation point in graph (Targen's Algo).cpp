#include <bits/stdc++.h>
using namespace std;
// Video : https://www.youtube.com/watch?v=64KK9K4RpKE
// Articile : https://www.geeksforgeeks.org/articulation-points-or-cut-vertices-in-a-graph/
// TC : O(V + E)
// SC : O(V) if not care about recursion stack

void dfs(int curr, vector<vector<int>>&adj, vector<int>&low, vector<int>&disc, vector<int>& parent, vector<bool>&articulation){
    static int time = 0;
    // set low and discovery time = time
    low[curr] = disc[curr] = time++;
    int children = 0;

    for(int nei : adj[curr]){
        if(disc[nei]==-1){
            // increase child count
            children++;

            // make nei's parent = currr
            parent[nei] = curr;

            // recursive call 
            dfs(nei, adj, low, disc, parent, articulation);

            // checking back edge
            low[curr] = min(low[nei], low[curr]);
            
            // Case 1 : curr == root & it has more than 1 child
            if(parent[curr]==-1 && children > 1)
                articulation[curr] = true;

            // Case 2 : curr != root & it has child with no back edge
            if(parent[curr]!=-1 && low[nei]>=disc[curr])
                articulation[curr] = true;

        }else if(parent[curr]!=nei){
            // Finding the back edge
            // but avoid the parent because we assumes parent node is removed
            low[curr] = min(low[curr], disc[nei]);
        }
    }
}

vector<int> getArticulationPoints(int N, vector<vector<int>> &adj){
    // low -> lowest back edge can possible by ith node
    // disc -> discovery time of the node
    // parent -> store the paretnt of ith node
    // articulation -> store wheateher it is articulation point or not
    vector<int> low(N, -1), disc(N, -1), parent(N, -1);
    vector<bool> articulation(N, false);

    for(int i=0; i<N; i++)
        if(disc[i]==-1)
            dfs(i, adj, low, disc, parent, articulation);

    vector<int> articulationPoints;
    for(int i=0; i<N; i++){
        if(articulation[i])
            articulationPoints.push_back(i);
    }

    return articulationPoints;
}

int main(){
    int N, E;
    // N-> number of vertices
    // E-> number of edges
    cin >> N >> E;

    vector<vector<int>> adj(N);

    for(int i=0; i<E; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    vector<int> artics = getArticulationPoints(N, adj);

    cout << "Articulation Points are : ";
    for(int i : artics)
        cout << i << " ";
    cout << endl;
}

// Sample Case 1
// 5 10
// 0 1
// 1 0
// 1 2
// 2 1
// 2 0 
// 0 2
// 0 3
// 3 0
// 3 4
// 4 3


