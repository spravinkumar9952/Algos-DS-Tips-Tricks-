vector<int> mana(string &str){
    string s="#";
    for(char c : str){
        string ch ;
        ch += c;
        s+= ch + "#";
    }

    int l = 0, r = -1, N = s.size();
    vector<int> P(N);

    for(int i=0; i<N; i++){

        int len = 1;

        if(i <= r){
            if(r-i+l < 0)
                len = r-i;
            else
                len = min(r-i, P[l+r-i]);
        }

        while(i-len >= 0 && i+len < N && s[i-len]==s[i+len]){
            len++;
        }

        P[i] = len-1;
        if(i + len > r){
            l = i-len;
            r = i+len;
        }
    }

    return P;
}
