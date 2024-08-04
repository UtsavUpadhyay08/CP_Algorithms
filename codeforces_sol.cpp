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
#define yes cout << "YES"
#define no cout << "NO"
#define pno cout << -1

#ifdef UTSAV
#include "handle_debug.hpp"
#define debug(...) cout<<'[';debug_print(#__VA_ARGS__, __VA_ARGS__);cout<<"]\n";
#else
#define debug(...)
#endif

const ll mod=1e9+7;

#define fori(i,a,b) for(ll i=a;i<b;i++)
#define vprint(v) for (auto it : v) cout << it << " "
#define all(a) a.begin(),a.end()

ll gcd(ll a, ll b){return b==0?a:gcd(b,a%b);}
ll lcm(ll a, ll b){return (a/gcd(a,b))*b;}


void solve(){
	ll n;cin>>n;
	string s;cin>>s;
	ll ans=1,chnc=1;
	fori(i,1,n){
		debug(i,chnc);
		if(s[i]==s[i-1]){
			if(chnc==1){
				ans++;
				chnc=0;
			}
			else chnc=1;
		}
		else{
			ans++;
			chnc=1;
		}
	}
	cout<<ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
	solve();
    // ll t;cin>>t;while(t--){solve();cout<<"\n";}
    return 0;
}