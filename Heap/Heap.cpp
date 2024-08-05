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

class Heap{
	protected:
	ll n;
	vll tree;
	public:
	Heap(ll n){
		this->n=n;
		tree.resize(n+1,0);
	}
};

class MaxHeap:public Heap{
	public:
	void heapify(ll i){
		ll l=2*i+1,r=2*i+2,largest=i;
		if(l<n && tree[l]>tree[largest]) largest=l;
		if(r<n && tree[r]>tree[largest]) largest=r;
		if(largest!=i){
			swap(tree[largest],tree[i]);
			heapify(largest);
		}
	}
};


void solve(){
	ll n;cin>>n;
	// vll a(n);for(auto &x:a) cin>>x;
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