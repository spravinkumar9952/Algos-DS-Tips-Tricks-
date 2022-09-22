class Solution {
public:
    int dp[11][2][1<<10];
    int solve(vector<int>&digits, int ind,int tight, int mask){
        
        // Base Case
        if(ind==digits.size()){
            return mask!=0;
        }
        
        // Memo Case
        if(dp[ind][tight][mask]!=-1) return dp[ind][tight][mask];
        
        // Find the limit 
        // if previous also tight and this is also going to be tight
        int limit = tight ? digits[ind] : 9;
        
        // total ways
        int poss = 0;
        
        for(int i=0; i<=limit; i++){
            // avoid not fessable cases
            if(mask&(1<<i)) continue;
            
            // create new Mask by choosing the i digit
            // but special case is if i is zero and we didn't meet any non zero value yet then newMask must want to be zero
            int newMask = (i==0 && mask==0) ? 0 : mask|(1<< i);
            
            // if preDigit also tight and this digit also reached the limit then set newTight = 1
            int newTight = tight && i==limit;
            
            // search the other possibles
            poss += solve(digits, ind+1, newTight, newMask);
        }
        
        // store and return 
        return dp[ind][tight][mask]=poss;
    }
    int countSpecialNumbers(int n) {
        vector<int> digits;
        memset(dp, -1, sizeof(dp));
        
        // convert number into digits array by setting MSD as 0 index
        while(n){
            digits.push_back(n%10);
            n/=10;
        }
        reverse(digits.begin(), digits.end());
        
        // call recursive function
        return solve(digits, 0, 1, 0);
    }
};
