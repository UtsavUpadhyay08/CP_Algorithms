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

void solve() {
    ll n,k;cin>>n>>k;
    vll a(n);for(auto &x:a) cin>>x;
    vll b(k);for(auto &x:b) cin>>x;

    mll mp;
    fori(i,0,n) mp[a[i]]=b[i];
    ll ans=0;
    
    for(auto it=mp.begin();it!=mp.end();it++){
        ll vl=0;

        if(mp.find(it->f+1)!=mp.end()) vl=mp[it->f+1];
        ll vl2=min(it->sc,k/(it->f)),val=k-(vl2*(it->f)),tmp=0;
        
        if(vl>0){
            tmp=min(vl,val/((it->f)+1));
            val-=tmp*((it->f)+1);
        }
        ans=max(ans,tmp*(it->f)*2+tmp);
        ll lft=vl-tmp;
        tmp-=min(min(tmp,val),lft);
        ans=max(ans,tmp*(it->f)*2+tmp);
    }
    cout<<ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
	// solve();
    ll t;cin>>t;while(t--){solve();cout<<"\n";}
    return 0;
}