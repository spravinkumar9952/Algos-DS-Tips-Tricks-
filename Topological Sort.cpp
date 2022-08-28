void topoSort(vector<vector<int>>& edges, int N){
    vector<vector<int>> graph(N);
    vector<int> in(N);

    for(auto i : edges){
        graph[i[0]].push_back(i[1]);
        // Calculate indegree
        in[i[1]]++;
    }
    queue<int> q;
    for(int i=0; i<N; i++){
        // if indegree == 0 then it is starting node (parent Node)
        if(in[i]==0){
            q.push(i);
        }
    }

    while(!q.empty()){
        int curr = q.front(); 
        q.pop();
        // Topo Order printing
        cout << curr << " ";
        // delete the node
        for(int nei : graph[curr]){
            in[nei]--;      // reduce the nei in degree 
            if(in[nei]==0) // same what we follow above
                q.push(nei);
        }
    }
    // If it has cycle some of the nodes should not be prited 
    // that indicates cycle
}
