// Start of the Program

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
ll power(ll x, ll y){
    ll res = 1;
    while (y){
        if (y % 2 == 1)
            res = (res * x);
        y = y >> 1;
        x = (x * x);
    }
    return res;
}


void solve(){
    ll n;
    cin >> n;
    vll a(n);
    map<ll,ll> m;
    // ll sum = 0;
    for(ll i=0;i<n;i++){
        cin >> a[i];
        m[a[i]]++;
        // m[-a[i]]++;
        // sum += a[i];
    }
    if(n == 1){
        if(a[0] == 0) {
            yes();
        }
        else {
            no();
        }
        return;
    }
    for(auto x : m){
        if(x.s > 1){
            yes();
            return;
        }
        if(x.f == 0){
            yes();
            return;
        }
    }
    ll mask = 1;
    mask = power(3,n);
    for(ll i=1;i<mask;i++){
        ll sum = 0;
        ll cnt = 0;
        ll tmp = i;
        vll here;
        for(ll j=0;j<n;j++){
            if(tmp%3 == 1){
                sum += a[j];
                cnt++;
                here.pb(a[j]);
            }
            else if(tmp%3 == 2){
                sum -= a[j];
                here.pb(-a[j]);
                cnt++;
            }
            tmp /= 3;
        }
        if(sum == 0){
            yes();
            // cout << "func";
            // putvll(here);
            return;
        }
    }
    no();
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

// End of the Program
