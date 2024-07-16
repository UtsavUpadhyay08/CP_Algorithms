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


class Graph{
	ll n;
	vector<vpll> adj;
	vll link,size;
	public:
	Graph(ll n){
		this->n=n;
		vector<vpll> adj(n+1);
		this->adj=adj;
		vll link(n+1),size(n+1,1);
		fori(i,0,n+1) link[i]=i;
		this->link=link;
		this->size=size;
	}
	void addedge(ll a,ll b,ll wt=0ll){
		adj[a].pb({b,wt});
		// adj[b].pb({a,wt});			//if directed graph comment this
	}
	ll find(ll a){
		if(link[a]==a) return a;		// finds the parent
		return find(link[a]);
	}
	bool same(ll a,ll b){				//Check for same parent
		return find(a)==find(b);
	}
	void unite(ll a,ll b){
		a=find(a);
		b=find(b);
		if(size[a]<size[b]) swap(a,b);
		size[a]+=size[b];
		link[b]=a;
		debug(a,b)
		debug(link)
		debug(size)
	}
};


void solve(){
	ll n,m;cin>>n>>m;
	Graph g(n);
	fori(i,0,m){
		ll a,b;cin>>a>>b;
		g.addedge(a,b);
		g.unite(a,b);
	}
	debug(g.same(3,5))
	// vll a(n);for(auto &x:a) cin>>x;
	// string s;cin>>s;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
	solve();
    // ll t;cin>>t;while(t--){solve();cout<<"\n";}
    return 0;
}