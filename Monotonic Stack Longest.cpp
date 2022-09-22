// Problem : Leetcode 81. Largest Rectangle in Histogram
// Alogorithm : Monotonic Stack

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int N = heights.size();
        
        vector<int> leftInd(N);
        vector<int> rightInd(N);
        
        stack<int> st;
        
        // Find the ( left Immediate smaller index + 1) == ( left longest greater index )
        for(int i=N-1; i>=0; i--){
            while(!st.empty() && heights[st.top()]>heights[i]){
                leftInd[st.top()] = i+1;
                st.pop();
            }
            st.push(i);
        }
        // remaining elements don't have longest max element
        // so set the 0th index as the longest max element
        while(!st.empty()){
            leftInd[st.top()] = 0;
            st.pop();
        }
        
        // Similarly,
        // Find the ( Right Immediate Min element - 1) == (right longest greater Index)
        for(int i=0; i<N; i++){
            while(!st.empty() && heights[st.top()]>heights[i]){
                rightInd[st.top()] = i-1;
                st.pop();
            }
            st.push(i);
        }
        
        // Remainig elements don't have immediate min element to its right
        // so set N-1th index as right longest greater Index
        while(!st.empty()){
            rightInd[st.top()] = N-1;
            st.pop();
        }
        
        int area = 0;
        for(int i=0; i<N; i++){
            area = max(area, (rightInd[i]-leftInd[i]+1)*heights[i]);
        }
        return area;
    }
};
