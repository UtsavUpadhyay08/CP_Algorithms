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

vll f(vll a,vll b,vll c,ll tot){
	vll ans;
	auto itr=lower_bound(all(a),tot);
	if(itr==a.end()){
		return ans;
	}
	ll ind2=itr-a.begin()+1;
	auto itr2=lower_bound(b.begin()+ind2,b.end(),b[itr-a.begin()]+tot);
	if(itr2==b.end()){
		return ans;
	}
	ll ind3=itr2-b.begin()+1;
	auto itr3=lower_bound(c.begin()+ind3,c.end(),c[itr2-b.begin()]+tot);
	if(itr3==c.end()){
		return ans;
	}
	ll n=a.size();
	ans={1,ind2,ind2+1,ind3,ind3+1,n};
	return ans;
}

void solve(){
	ll n;cin>>n;
	vll a(n),b(n),c(n);for(auto &x:a) cin>>x;
	for(auto &x:b) cin>>x;
	for(auto &x:c) cin>>x;
	fori(i,1,n){
		a[i]+=a[i-1];
		b[i]+=b[i-1];
		c[i]+=c[i-1];
	}
	ll tot=ceil(a[n-1]/3.0);
	vll ans;
	ans=f(a,b,c,tot);
	if(!ans.empty()){
		cout<<ans[0]<<' '<<ans[1]<<' '<<ans[2]<<' '<<ans[3]<<' '<<ans[4]<<' '<<ans[5];
		return;
	}
	ans=f(a,c,b,tot);
	if(!ans.empty()){
		cout<<ans[0]<<' '<<ans[1]<<' '<<ans[4]<<' '<<ans[5]<<' '<<ans[2]<<' '<<ans[3];
		return;
	}
	ans=f(b,a,c,tot);
	if(!ans.empty()){
		cout<<ans[2]<<' '<<ans[3]<<' '<<ans[0]<<' '<<ans[1]<<' '<<ans[4]<<' '<<ans[5];
		return;
	}
	ans=f(b,c,a,tot);
	if(!ans.empty()){
		cout<<ans[4]<<' '<<ans[5]<<' '<<ans[0]<<' '<<ans[1]<<' '<<ans[2]<<' '<<ans[3];
		return;
	}
	ans=f(c,a,b,tot);
	if(!ans.empty()){
		cout<<ans[2]<<' '<<ans[3]<<' '<<ans[4]<<' '<<ans[5]<<' '<<ans[0]<<' '<<ans[1];
		return;
	}
	ans=f(c,b,a,tot);
	if(!ans.empty()){
		cout<<ans[4]<<' '<<ans[5]<<' '<<ans[2]<<' '<<ans[3]<<' '<<ans[0]<<' '<<ans[1];
		return;
	}
	pno;
	
	
	// string s;cin>>s;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
	// solve();
    ll t;cin>>t;while(t--){solve();cout<<"\n";}
    return 0;
}