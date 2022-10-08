// Topic : Longest Prefix which is equal to Suffix
// LCP Table
// Used in KMP alogorithm for string Matching

// For More Info and Images Refer here :
// https://leetcode.com/problems/implement-strstr/discuss/535326/Java-KMP-Solution-O(m%2Bn)-Clean-code
// https://www.youtube.com/watch?v=ziteu2FpYsA

string longestPrefix(string s) {
    // i, j are two pointers. j always start from 1 to avoid whole string always prefix and suffix
    int i = 0, j = 1, N = s.size();
    
    // LPS array which store longest prefix & suffix till that point
    vector<int> lsp(N+1); 
    
    while(j<N){
        // positive case 
        if(s[i]==s[j]){
            // store the lps length value of jth index to len i+1
            lsp[j++] = ++i;
        }else{
            // Negative case .. 
            // Now we want to move back until we found the valid prefix matching
            // if i become 0 then we can't move furethre so that time we want to move j forward 
            if(i) i = lsp[i-1];
            else j++; 
        }
    }
    // return the longest prefix
    return s.substr(0,lsp[N-1]);
}
