
// TC : O(N^3)
vector<vector<bool>> getTransitMat(vector<vector<int>>& edges, int N){
    // Transit Mat 
    vector<vector<bool>> transit(N, vector<bool>(N, false));
    
    // Add the edges as reachable 
    for(vector<int> i : edges){
        transit[i[0]][i[1]] = true;
    }

    for(int k=0; k<N; k++){
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                // if i->k && k->j then i->j
                if(transit[i][k] && transit[k][j]){
                    transit[i][j]  = true;
                }
            }
        }
    }
    return transit;
}
