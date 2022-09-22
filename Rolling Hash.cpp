// Algorithm : Robin Karb Algorithm
// Topic : Pattern Matching
// Concepts : Rolling Hash
class Solution {
public:
    bool patternMatching(string& str, string& pat) {
        // Base Number for Hahsing 
        int base = 26;
        
        // Prime number mod to control the overflow of Hash value
        int prime = 5381;
        
        int N = pat.size();
        int M = str.size();
        
        int patHash = 0;   // Pattern Hash Value
		int rollHash =0;   // String hash (Rolling Hash)
        int shiftPow = 1;  // power value for remove the first digit while rolling the hash value

        // Compute the shiftPower value =pow(base^N-1);
        for(int i=0; i<N-1; i++){
            shiftPow = (shiftPow*base)%prime;
        }
        
        // Compute the Hash
        for(int i=0; i<N; i++){
            patHash = (patHash*base+pat[i]-'a')%prime;
            rollHash = (rollHash*base+str[i]-'a')%prime;
        }
        
        for(int i=0; i<=M-N; i++){
        	// Add the i+N-1th char to the hash 
            if(i){
                 rollHash = (rollHash*base+str[i+N-1]-'a')%prime;
            }
            
            // check rollhash matched with patHash
            if(patHash==rollHash){
                for(int j=0; j<N; j++){
                    // Negative Case
                    if(str[i+j]!=pat[j]) goto end;
                }
                // Positive Case
                // Matched at ith (starting position of Pattern) index
                return true;
                end:;
            }
            
            // remove the curr char from hash 
            rollHash = (rollHash - (shiftPow*(str[i]-'a'))%prime+prime)%prime;
        }
        
        // Not Matched
        return false;
    }
};
