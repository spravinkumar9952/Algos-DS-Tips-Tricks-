// TC: O(N)
// TC: O(1)

int solve(string &s){
    int mp[26];
    int dist = 0, N = s.size(), ans = 0;
    for(char c : s){
        mp[c-'a']++;
        if(mp[c-'a'] == 1) dist++;
    }

    int j = 0;
    for(int i = 0; i<N; i++){
        while(j < N && dist > 2){
            mp[s[j] -'a']--;
            if(mp[s[j] -'a'] == 0) dist--;
            j++;
        }

        if(dist <= 2){
            ans += N-j+1;
        }
      
        mp[s[i] -'a']++;
        if(mp[s[i] -'a'] == 1) dist++;
    }

    return ans;

}



int main(){
    string s = "aaffbbcc";
    cout << "Ans " << solve(s);
}
