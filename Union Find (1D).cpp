class UF{
public:
    // Parent store the parent of the index
    // rank store the number of child it has  
    vector<int> parent, rank;
    
    // Initialize parent , rank
    UF(int N){
        parent.resize(N,-1);
        rank.resize(N,1);
    }
    
    // Find the parent of the element
    int Find(int child){
        // if current element is 
        if(parent[child]==-1) return child;
        
        // change all it's path element to its parent (Reduce the time complexity
        return (parent[child] = Find(parent[child]));
     
    }
    void Union(int x, int y){
        int p1 = Find(x);
        int p2 = Find(y);
    
        if(p1==p2) return;
        // make which has more rank as parent 
    
        if(rank[p1]>rank[p2]){
            // p2 -> p1 (Parent p1)
            parent[p2] = p1;
            // uodate the rank of p1
            rank[p1]+=rank[p2];
        }else{
            // p1-> p2 (Parent p2)
            parent[p1] = p2;
            // update the rank of p2
            rank[p2] += rank[p1];
        }
    }
};
