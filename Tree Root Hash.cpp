



// Problem: https://codeforces.com/contest/1800/problem/G
// Author : spk++ (Pravinkumar S)
 
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef
tree<
  int, // dataType of rb_tree map -> pair<key, val> 
  null_type,
  greater<int>, // greater -> desc ,less-> asc, same data 
  rb_tree_tag,
  tree_order_statistics_node_update>
ordered_set;
 
#define vec vector
#define endl '\n'
#define ll long long
#define all(x) (x).begin(), (x).end()
#define inArr(arr) for(auto &i : arr) cin >> i;
#define inMat(mat) for(auto &i : mat) inArr(i)
 
// ---Debug Starts---
void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}
 
template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}

// ---Debug Ends--
 


long long mod = 1e9+7;
vec<int> bfsX={-1,-1,-1,0,0,0,1,1,1}, bfsY={-1,0,1,-1,0,1,-1,0,1};
vec<vec<int>> bfs4={{0,-1}, {0,1}, {-1, 0}, {1, 0}};
vec<vec<int>> bfs8={{0,-1}, {0,1}, {-1, 0}, {1, 0},{-1, -1}, {1,-1},{1,1},{-1, 1}};
 
template<class T> void outArr(vector<T> &arr){for(T i : arr) cout << i << " "; cout << endl;}
template<class T> void outMat(vector<vector<T>> &mat){for(vector<T> i : mat)outArr(i);}
template<class T> inline T Bit(T x, int i) { return (x >> i) & 1;}
 
void localInput(){
    #ifndef ONLINE_JUDGE
        #define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
    #else
    #define debug(x...)
    #endif
}
 
void solve();
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    localInput();
    int T=1;
    cin >> T;
    for(int i=1; i<=T; i++){
        // cout << "case#" << i << ": " << endl;
        solve();
    }
    return 0;
}



void solve(){
    // Start Here 
    int N;
    cin >> N;

    vector<vector<int>> root(N);

    for(int i=0; i<N-1; i++){
        int u, v;
        cin >> u >> v;
        u--, v--;

        root[u].push_back(v);
        root[v].push_back(u);
    }

    vector<bool> sym;
    map<vector<int>, int> hash;
    

    auto dfs = [&](auto& dfs, int curr, int par)->int{
        
        vector<int> arr;
        
        for(int nei : root[curr]){
            if(nei == par) continue;

            arr.push_back(dfs(dfs, nei, curr));
        }
        
        sort(all(arr));
        if(hash.find(arr) == hash.end()){
            // do the algo for new type of subtree 
            // this subtree is not visited earlier
            hash[arr] = sym.size(); // here hash value update (You can use timer / depending updon the problem)

            bool isSym = true;
            int odd = 0;

            unordered_map<int,int> frq;
            for(int i : arr) frq[i]++;

            for(auto &i : frq){
                if(i.second &1){
                    odd++;
                    isSym = sym[i.first];
                }
            }

            sym.push_back(isSym && odd <= 1);
        }
        // else we already calculated this subtree

        return hash[arr];
    };

    dfs(dfs, 0, -1);
    
    cout << (sym.back() ? "YES" : "NO") << endl;
}
