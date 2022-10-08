class Trie{
    public : 
    vector<Trie*> child; // next pointer array
    bool isEnd ; // Indicates the word end
    int ctr; // Number of words have that prefix

    Trie(){
        child.resize(26, NULL);
        isEnd = false;
        ctr = 0;
    }

    void add(Trie *root, const string &s){
        for(char c : s){
            int pos = c-'a';
            if(!root->child[pos]){
                root->child[pos] = new Trie();
            }
            root = root->child[pos];
        }
        root->isEnd = true;
    }

    bool search(Trie *root, const string &s){
        for(char c : s){
            int pos = c-'a';
            if(!root->child[pos]) 
                return false;
            root = root->child[pos];
        }
        return root->isEnd;
    }

    // Find the prefix matches length
    int prefixSearch(Trie *root, const string &s){
        int len = 0; // Length of the prefix
        for(char c : s){
            int pos = c-'a';
            if(!root->child[pos]) 
                break;
            root = root->child[pos];
            len++;
        }
        return len;
    }
};
