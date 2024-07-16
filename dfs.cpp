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
	ll n,e;
	vector<vpll> adj;
	vector<bool> vis;
	// vll vis;
	vll dis;
	public:
	Graph(ll n){
		vector<vpll> adj1(n+1);
		vector<bool> vis1(n+1,false);
		// vll vis1(n+1,0);
		vll dis1(n+1,-1);
		this->adj=adj1;
		this->vis=vis1;
		this->dis=dis1;
		
	}
	void addedge(ll a,ll b,ll wt){
		adj[a].pb({b,wt});
		// adj[b].pb({a,wt});			//if directed graph comment this
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
	bool isCycle(ll node,ll parent){
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
};


void solve(){
	ll n,m;cin>>n>>m;
	Graph g(n);
	fori(i,0,m){
		ll a,b;cin>>a>>b;
		g.addedge(a,b,0);
	}
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