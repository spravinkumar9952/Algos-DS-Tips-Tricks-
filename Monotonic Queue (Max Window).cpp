//                                              window size
vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    int N = nums.size();
    // duble ended queue
    deque<int> dq;
    
    // window max array
    vector<int> ans;
    
    for(int i=0; i<N; i++){
        // delete out of range elements which is in front
        // change i-k+1 to change the window size
        while(dq.empty()==false && dq.front()<i-k+1 ) dq.pop_front();
        
        // delete not fusable elements which is recently added into queue
        while(dq.empty()==false && nums[dq.back()]<=nums[i]) dq.pop_back();
        
        // add curr index to dq
        dq.push_back(i);
        
        // q.front is curr max
        if(i>=k-1){
            ans.push_back(nums[dq.front()]);
        }
    }
    return ans;
}
