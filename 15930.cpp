#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <complex>
#include <queue>
#include <set>
#include <unordered_set>
#include <list>
#include <chrono>
#include<cstring>
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

#define ll long long
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pdd;
typedef vector<ll> vll;
typedef vector<int> vii;
typedef vector<bool> vb;
typedef vector<ld> vld;
// typedef vector<vector<int>> vvii;
typedef vector<vector<ll> > vvll;
typedef vector<vector<pll> > vvpll;
typedef vector<pll> vp;
typedef vector<pii> vpii;

#define fastio()                      \
	ios_base::sync_with_stdio(false); \
	cin.tie(NULL);

#define forn(i, s) for (ll i = 0; i < s; i++)
#define forsn(i, s, e) for (ll i = s; i < e; i++)
#define rforn(i, s) for (ll i = s; i >= 0; i--)
#define rforsn(i, s, e) for (ll i = s; i >= e; i--)
#define MEMS(x,t) memset(x,t,sizeof(x));

#define dbg(x) cout << #x << " = " << x << endl
#define dbg2(x, y) cout << #x << " = " << x << " , " << #y << " = " << y << endl;
#define dbg3(x, y, z) cout << #x << " = " << x << " , " << #y << " = " << y << " , " << #z << " = " << z << endl;
#define dbg4(w, x, y, z) cout << #w << " = " << w << " , " << #x << " = " << x << " , " << #y << " = " << y << " , " << #z << " = " << z << endl;

#define mp make_pair
#define pb push_back
#define eb emplace_back
#define ff first
#define ss second
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())

#define putvll(v)         \
	for (auto x : v)      \
		cout << x << " "; \
	cout << endl
#define putvp(v)     \
	for (auto x : v) \
	cout << x.f << " " << x.s << endl
#define putvvll(v)            \
	for (auto x : v)          \
	{                         \
		for (auto y : x)      \
		{                     \
			cout << y << " "; \
		}                     \
		cout << endl;         \
	}
#define out(x)         \
	cout << x << "\n"; \
	return
#define read(a)       \
	for (auto &x : a) \
		cin >> x;

const double eps = 1e-12;
const double PI = acos(-1.0);
const ll INF = 1e18;
const ll MOD = 1e9 + 7;
const ll nax = 5e5 + 5;

#define endl "\n"
#define Endl "\n"

#define yes() cout << "YES\n"
#define no() cout << "NO\n"

// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>

// using namespace __gnu_pbds;
// using namespace std::chrono;

// template <typename T>
// using ordered_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

ll int gcd(ll int a, ll int b){if (a == 0)return b;return gcd(b % a, a);}
bool isPowerOfTwo(ll int x) { return x && (!(x & (x - 1))); }

void solve()
{
	ll int i, n, ans, k, m, j;
    ll int a, b, c;

	cin >> a >> b >> c;
    n = a + b + c;

    if(max(b,c) >= a)
    cout << max(b,c) - a + 1 << " ";
    else
    cout << 0 << " ";
    if(max(a,c) >= b)
    cout << max(a,c) - b + 1 << " ";
    else
    cout << 0 << " ";
    if(max(b,a) >= c)
    cout << max(b,a) - c + 1 << " ";
    else
    cout << 0 << " ";
    cout << endl;


	return;
}

// Driver Code
int main()
{
	fastio();

	// freopen("input.txt","r",stdin);
	// freopen("output.txt","w",stdout);

	ll int t = 1, i;

	cin >> t;

	while (t--)
		solve();

	return 0;
}

