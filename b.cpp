#include<bits/stdc++.h>
#include<set>
#include<vector>

using namespace std;

#define ll long long
#define ld long double
#define endl "\n"
#define pb push_back
#define mp make_pair
#define fastio() ios_base :: sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

const ll MOD = 1e9+7;
const ll INF = 1e18;
const double PI = acos(-1.0);

ll lcm(ll a,ll b){
    return a*b/__gcd(a,b);
}
ll power_mod(ll a,ll b,ll p){
    if(b == 0)return 1;
    if(b == 1)return a;
    if(b%2)return a*(power_mod((a*a)%p,b/2,p))%p;
    else return power_mod((a*a)%p,b/2,p);
}
ll power(ll a,ll b){
    if(b == 0)return 1;
    if(b == 1)return a;
    if(b%2)return a*power(a*a,b/2);
    else return power(a*a,b/2);
}
ll div_mod(ll a,ll b,ll p){
    return a*power(b,p-2)%p;
}


void solve(){
    string s;
    cin>>s;
    ll n = s.length();
    ll cnt = 0;
    stack<char> st;
    for(ll i=0;i<n;i++){
        if(s[i] == '['){
            // cnt++;
            st.push('[');
        }
        else if(s[i] == ']' && !st.empty()){
            st.pop();
            cnt++;
        }

    }
    while(!st.empty())st.pop();
    for(ll i=0;i<n;i++){
        if(s[i] == '('){
            // cnt++;
            st.push('(');
        }
        else if(s[i] == ')' && !st.empty()){
            st.pop();
            cnt++;
        }

    }
    cout<<cnt<<endl;

}


int main(){
    fastio();
    ll t;
    cin>>t;
    while(t--){
        solve();

    }
    return 0;
}

