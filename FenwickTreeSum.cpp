class FenwickTree{
public:
    int N;
    vector<int> tree;
    FenwickTree(vector<int>& arr){
        N = arr.size();
        tree.resize(N+1);

        for(int i=1; i<=N; i++){
            tree[i] = arr[i-1];
        }

        for(int i=1; i<=N; i++){
            int parent = i + lsb(i);
            if(parent <= N) tree[parent] += tree[i];
        }
    }

    int lsb(int val){
        return val & -val;
    }

    int prefixSum(int pos){
        int sum = 0;
        while(pos){
            sum += tree[pos];
            pos &= ~lsb(pos);
        }
        return sum;
    }

    // start and ends are 1 based index
    int sumRange(int start, int end){
        return prefixSum(end)-prefixSum(start-1);
    }

    void update(int pos, int val){
        while(pos <= N){
            tree[pos] += val;
            pos += lsb(pos);
        }
    }
};
