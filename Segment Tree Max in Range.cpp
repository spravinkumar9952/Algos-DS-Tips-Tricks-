class SegmentTree{
public:
    vector<int> segTree;
    SegmentTree(int N){
        segTree.resize(4*N, 0);
    }
    
    //          building array , 0 ,        N,          0
    void build(vector<int>&nums, int low, int high, int ind){
        if(low==high){
            segTree[ind] = nums[low];
            return ;
        }

        int mid = low + (high-low)/2;

        build(nums, low, mid, 2*ind+1);
        build(nums, mid+1, high, 2*ind+2);

        segTree[ind] = max(segTree[2*ind+1], segTree[2*ind+2]);
    }

    int query(int low, int high, int left, int right, int ind){
        

        if(low>=left && high<=right) return segTree[ind];
        if(low>right || high<left) return 0;

        int mid = low+ (high-low)/2;

        int lMax = query(low, mid, left, right , 2*ind+1);
        int rMax = query(mid+1, high, left, right, 2*ind+2);

        return max(lMax, rMax);
    }

    void update(int pos, int val, int ind,  int low, int high){
        if(low>pos || high<pos) return ;
        if(low == high){
            segTree[ind] = val;
            return ;
        }

        int mid = low + (high - low)/2;

        update(pos, val, 2*ind+1, low, mid);
        update(pos, val, 2*ind+2, mid+1, high);

        segTree[ind] = max(segTree[2*ind+1] , segTree[2*ind+2]); 
    }
};
