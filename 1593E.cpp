#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h> 
#include <complex>
#include <queue>
#include <set>
#include <unordered_set>
#include <list>
#include <chrono>
#include <random>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <stack>
#include <iomanip>
#include <fstream>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<ld,ld> pdd;
typedef vector<ll> vll;
typedef vector<int> vii;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef vector<ld> vld;
typedef vector<vector<int> > vvii;
typedef vector<vector<ll> > vvll;
typedef vector<vector<pll> > vvpll;
typedef vector<pll> vp;
typedef vector<pii> vpii;

#define fastio() ios_base::sync_with_stdio(false); cin.tie(NULL);

#define forn(i,s) for(ll i = 0; i < s; i++)
#define forsn(i,s,e) for(ll i = s; i < e; i++)
#define rforn(i,s) for(ll i = s; i >= 0; i--)
#define rforsn(i,s,e) for(ll i = s; i >= e; i--)

#define dbg1(x) cout<<#x<<" = "<<x<<endl;
#define dbg2(x,y) cout <<#x<<" = "<<x<<", "<<#y<<" = "<<y<<endl;
#define dbg3(x,y,z) cout <<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<endl;
#define dbg4(w,x,y,z) cout<<#w<<" = "<<w<<", "<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<endl;
#define dbg5(v,w,x,y,z) cout<<#v<<" = "<<v<<", "<<#w<<" = "<<w<<", "<<#x<< " = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<endl;
#define dbg6(u,v,w,x,y,z) cout<<#u<<" = "<<u<<", " <<#v<<" = "<<v<<", "<<#w<<" = "<<w<<", "<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<endl;
#define GET_MACRO(_1,_2,_3,_4,_5,_6,NAME,...) NAME
#define dbg(...) GET_MACRO(__VA_ARGS__,dbg6,dbg5, dbg4, dbg3, dbg2, dbg1)(__VA_ARGS__)


#define mp make_pair
#define pb push_back
#define eb emplace_back
#define f first
#define s second
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())


#define putvll(v) for(auto x : v)cout << x << " ";cout << endl;
#define putvp(v) for(auto x : v)cout << x.f << " " << x.s << endl;
#define putvvll(v) for(auto x : v){for(auto y : x){cout << y << " ";}cout << endl;} 
#define out(x) cout<<x<<"\n";return;
#define read(a) for(auto &x : a) cin >> x;
#define MEMS(x,t) memset(x, t, sizeof(x));

const double eps = 1e-12;
const double PI = acos(-1.0);
const long long INF = 1e13;
const ll MOD = 1e9+7;

#define endl "\n" 
#define Endl "\n" 
#define nline "\n"

#define yes() cout << "YES\n";
#define no() cout << "NO\n";
 
 
ll ceil_div(ll x,ll y){
    return (x+y-1)/y;
}

 


void dfs(ll u,ll par,vll  &depth,ll cur,vvll &adj,vll &parent){
    for(auto v : adj[u]){
        if(v == par){
            continue;
        }
        dfs(v,u,depth,cur,adj,parent);
        depth[u] = max(depth[u],depth[v]+1);
        parent[v] = u;
    }
}

void dfs2(vvll &adj,ll u,ll par,vll &gone,vll &dist){
    for(auto v : adj[u]){
        if(v == par){
            continue;
        }
        dist[v] = dist[u] + 1;
        dfs2(adj,v,u,gone,dist);
        gone[u] = v;

    }
}




void solve(){
    ll n,k;
    cin >> n >> k;
    vvll adj(n);
    for(ll i=0;i<n-1;i++){
        ll u,v;
        cin >> u >> v;
        u--,v--;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    if(n <= 2){
        cout << 0 << endl;
        return;
    }

    vll ssz(n);
    vll gone(n);
    vll parent(n,-1);
    vll dist(n,0);

    ll ans = 0,node = -1;
    dfs2(adj,0,-1,gone,dist);
    for(ll i=0;i<n;i++){
        if(dist[i] > ans){
            ans = dist[i];
            node = i;
        }
    }
    ll node1 = node;
    dist.assign(n,0);
    gone.assign(n,0);
    dfs2(adj,node,-1,gone,dist);

    ans = 0,node = -1;
    for(ll i=0;i<n;i++){
        if(dist[i] > ans){
            ans = dist[i];
            node = i;
        }
    }

    queue<ll> q;
    q.push(node);
    vb vis(n,0);
    // vll parent(n,-1);
    assert(node != -1 && node1 != -1);
    parent.assign(n,-1);
    while(sz(q)){
        ll u = q.front();
        q.pop();
        for(auto v : adj[u]){
            if(!vis[v]){
                q.push(v);
                vis[v] = 1;
                parent[v] = u;
            }
        }
    }

    vll dia;
    ll i = node1;
    
    while(i != node){
        dia.pb(i);
        i = parent[i];
    }
    dia.pb(node);
    // putvll(dia);

    
    vll depth(n,1);
    ll root = dia[sz(dia)/2];
    
    dfs(root,-1,depth,0,adj,parent);

    if(sz(dia)%2 == 0){
        depth[root]--;
    }
    ans = n;
    for(ll i=0;i<n;i++){
        if(depth[i] <= k ){
            ans--;
        }
    }
    cout << ans << endl;

    


}
int main(){
    fastio(); 
    ll t = 1;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}