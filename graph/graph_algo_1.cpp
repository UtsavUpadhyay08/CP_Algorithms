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
	ll n;
	vector<vpll> adj;
	vector<bool> vis;
	set<pair<ll,pll>> edges;
	vll dis;
	vll link,size;
	// vector<vll> adj,dis;
	public:
	Graph(ll n){
		this->n=n;
		adj.resize(n+1);
		link.resize(n+1);
		size.resize(n+1,1);
		fori(i,0,n+1) link[i]=i;
		vis.resize(n+1,false);
		dis.resize(n+1,INF);
		//adj matrix
		// adj.resize(n+1,vll(n+1,INF));
		// dis.resize(n+1,vll(n+1,INF));
	}
	void addedge(ll a,ll b,ll wt=0ll){ 		//if undirected graph call this for a,b then b,a
		adj[a].pb({b,wt});
		edges.insert({wt,{a,b}});
		// adj[a][b]=wt;
		// dis[a][b]=wt;
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
	}
	ll prim(){
		priority_queue<pll> pq;
		pq.push({0,0});
		ll ans=0;
		while(!pq.empty()){
			ll node=pq.top().sc,wt=(-1)*pq.top().f;
			pq.pop();
			if(vis[node]) continue;
			vis[node]=true;
			ans+=wt;
			for(auto it:adj[node]){
				if(!vis[it.f]){
					pq.push({(-1)*it.sc,it.f});
				}
			}
		}
		return ans;
	}
	vector<pair<ll,pll>> kruskal(){
		vector<pair<ll,pll>> ans;
		while(((ll)ans.size())!=(n-1)){
			pair<ll,pll> p=*edges.begin();
			edges.erase(edges.begin());
			if(same(p.sc.f,p.sc.sc)) continue;
			ans.pb(p);
			unite(p.sc.f,p.sc.sc);
		}
		return ans;
	}
	vll bellman_ford(ll strt){
		dis[strt]=0;
		fori(i,0,n-1){
			for(auto e:edges){
				dis[e.sc.sc]=min(dis[e.sc.sc],e.f+dis[e.sc.f]);
			}
		}
		for(auto e:edges){
			if(dis[e.sc.sc]>(e.f+dis[e.sc.f])){			//negative cycle
				dis[strt]=-1;
			}
		}
		return dis;
	}
	// vector<vll> floyd_warshall(){
		// for(ll i=0;i<=n;i++) dis[i][i]=0;
		// for(ll k=0;k<=n;k++){
			// for(ll i=0;i<=n;i++){
				// for(ll j=0;j<=n;j++){
					// dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
				// }
			// }
		// }
		// return dis;
	// }
};


void solve(){
	ll n,m;cin>>n>>m;
	Graph g(n);
	fori(i,0,m){
		ll a,b,wt;cin>>a>>b>>wt;
		g.addedge(a,b,wt);
		g.addedge(b,a,wt);
		// g.unite(a,b);
	}
	// debug(g.bellman_ford(2));
	// debug(g.kruskal());
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