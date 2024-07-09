#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

#define ll long long int
typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;

#define vll vector<ll>
#define mll map<ll,ll>
#define pll pair<ll,ll>
#define vpll vector<pair<ll,ll>>
#define sll set<ll>

#define f first
#define sc second
#define pb push_back
#define yes cout<<"YES"
#define no cout<<"NO"
#define pno cout<<-1

#ifdef UTSAV
#include "handle_debug.hpp"
#define debug(...) cout<<'[';debug_print(#__VA_ARGS__,__VA_ARGS__);cout<<"]\n";
#else
#define debug(...)
#endif

const ll mod=1e9+7;
#define fori(i,a,b) for(ll i=a;i<b;i++)
#define vprint(v) for(auto it:v) cout<<it<<" "
#define all(a) a.begin(),a.end()

ll gcd(ll a,ll b){return b==0?a:gcd(b,a%b);}
ll lcm(ll a,ll b){return (a/gcd(a,b))*b;}

void solve(){
    ll n,m;cin>>n>>m;
    vector<vll> a(n,vll(m,0)),b(n,vll(m,0));
    fori(i,0,n){
        string s;
        cin>>s;
        fori(j,0,m) a[i][j]=(s[j]-'0');
    }
    fori(i,0,n){
        string s;
        cin>>s;
        fori(j,0,m) b[i][j]=(s[j]-'0');
    }
    fori(i,0,n-1){
        fori(j,0,m-1){
            while(a[i][j]!=b[i][j]){
                a[i][j]=(a[i][j]+1)%3;
			    a[i+1][j+1]=(a[i+1][j+1]+1)%3;
			    a[i][j+1]=(a[i][j+1]+2)%3;
			    a[i+1][j]=(a[i+1][j]+2)%3;
            }
        }
    }
    fori(i,0,n){
        if(a[i][m-1]!=b[i][m-1]){
        	no;
        	return;
        }
    }
    fori(j,0,m){
        if(a[n-1][j]!=b[n-1][j]){
        	no;
        	return;
        }
    }
    yes;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t;cin>>t;while(t--){solve();cout<<"\n";}
    return 0;
}