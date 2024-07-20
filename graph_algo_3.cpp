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
const ll INF=1e9;
#define fori(i,a,b) for(ll i=a;i<b;i++)
#define vprint(v) for (auto it : v) cout << it << " "
#define all(a) a.begin(),a.end()

ll gcd(ll a, ll b){return b==0?a:gcd(b,a%b);}
ll lcm(ll a, ll b){return (a/gcd(a,b))*b;}


class Graph{
	public:
	ll n;
	vector<vpll> adj;
	vector<bool> vis;
	vpll edges;
	Graph(ll n){
		this->n=n;
		adj.resize(n+1);
		vis.resize(n+1,false);
	}
	void addedge(ll a,ll b,ll wt=0ll){ 		//if undirected graph call this for a,b then b,a
		adj[a].pb({b,wt});
		edges.pb({a,b});
	}
};

class Kosaraju:public Graph{
	stack<ll> st;
	public:
	Kosaraju(ll n):Graph(n){}
	vector<vll> algo(){
		vector<vll> ans;
		fori(i,1,n+1) dfs1(i);
		reverse();
		while(!st.empty()){
			ll vl=st.top();
			st.pop();
			if(vis[vl]) continue;
			vll scc;
			dfs2(vl,scc);
			ans.pb(scc);
		}
		return ans;
	}
	void reverse(){
		vis.clear();
		vis.resize(n+1,false);
		adj.clear();
		adj.resize(n+1);
		for(auto it:edges) addedge(it.sc,it.f);
	}
	void dfs1(ll node){
		if(vis[node]) return;
		vis[node]=true;
		for(auto it:adj[node]){
			if(!vis[it.f]) dfs1(it.f);
		}
		st.push(node);
	}
	void dfs2(ll node,vll &scc){
		if(vis[node]) return;
		vis[node]=true;
		scc.pb(node);
		for(auto it:adj[node]) if(!vis[it.f]) dfs2(it.f,scc);
	}
};

void solve(){
	ll n,m;cin>>n>>m;
	Kosaraju g(n);
	fori(i,0,m){
		ll a,b;cin>>a>>b;
		g.addedge(a,b);
	}
	vector<vll> ans=g.algo();
	fori(i,0,ans.size()){
		debug(i);debug(ans[i]);
	}
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