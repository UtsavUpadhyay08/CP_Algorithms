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
	// vector<bool> vis;
	vll vis;
	vll dis,topo;
	vll indegree;
	public:
	Graph(ll n){
		this->n=n;
		adj.resize(n+1);
		dis.resize(n+1,-1);
		vis.resize(n+1,0);
		// vis.resize(n+1,false);
		indegree.resize(n+1,0);
		vector<vpll> adj(n+1);
	}
	void addedge(ll a,ll b,ll wt=0ll){  //if undirected call a,b then b,a
		adj[a].pb({b,wt});
		indegree[b]++;
	}
	void dfs(ll i){
		if(vis[i]) return;
		vis[i]=true;
		for(auto it:adj[i]){
			if(!vis[it.f]) dfs(it.f);
		}
	}
	void bfs(ll strt){
		queue<ll> q;
		q.push(strt);
		while(!q.empty()){
			ll vl=q.front();
			q.pop();
			if(vis[vl]) continue;
			vis[vl]=true;
			for(auto it:adj[vl]){
				if(!vis[it.f]) q.push(it.f);
			}
		}
	}
	vll djikstra(ll node){
		priority_queue<pll> pq;
		pq.push({0,node});
		dis[node]=0;
		while(!pq.empty()){
			pll vl=pq.top();
			pq.pop();
			if(vis[vl.sc]) continue;
			vis[vl.sc]=true;
			vl.f*=(-1);
			for(auto it:adj[vl.sc]){
				ll node2=it.f,wt=it.sc;
				if((dis[node2]==-1) || dis[node2]>(vl.f+wt)){
					dis[node2]=(vl.f+wt);
					pq.push({-1*dis[node2],node2});
				}
			}
		}
		return dis;
	}
	// bool isCycleDAG(ll i){			//Directed Graph
		// if(vis[i]) return true;
		// vis[i]=true;
		// bool ans=false;
		// for(auto it:adj[i]) ans=ans|isCycleDAG(it);
		// return ans;
	// }
	bool isCycle(ll node,ll parent){		//Undirected graph
		if(vis[node]==2) return false;
		if(vis[node]==1) return true;
		vis[node]=1;
		bool ans=false;
		for(auto it:adj[node]){
			if(it.f!=parent) ans=ans|isCycle(it.f,node);
		}
		vis[node]=2;
		return ans;
	}
	void topodfs(ll i){
		if(vis[i]==2) return;
		// if(vis[i]==1)   		//Cycle exists
		vis[i]=1;
		for(auto it:adj[i]){
			topodfs(it.f);
		}
		vis[i]=2;
		topo.pb(i);
	}
	vll toposort(){
		for(ll node=1;node<=n;node++){		//Change according to numbering of nodes
			topodfs(node);
		}
		reverse(all(topo));
		return topo;
	}
	vll kahn(){
		queue<ll> q;
		fori(i,1,n+1) if(indegree[i]==0) q.push(i);
		vll ans;
		while(!q.empty()){
			ll vl=q.front();
			q.pop();
			ans.pb(vl);
			for(auto it:adj[vl]){
				indegree[it.f]--;
				if(indegree[it.f]==0) q.push(it.f);
			}
		}
		if((ll)ans.size()>n) return {};
		return ans;
	}
};


void solve(){
	ll n,m;cin>>n>>m;
	Graph g(n);
	fori(i,0,m){
		ll a,b;cin>>a>>b;
		g.addedge(a,b);
	}
	// debug(g.toposort());
	// debug(g.kahn());
	// debug(g.isCycle(1,-1));
	// g.dfs(1);
	// debug(g.djikstra(1));
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