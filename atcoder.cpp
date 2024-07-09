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

void applyOperation(vector<vector<int>>& grid,int x1,int y1,int x2,int y2){
    grid[x1][y1]=(grid[x1][y1]+1)%3;
    grid[x2][y2]=(grid[x2][y2]+1)%3;
    grid[x1][y2]=(grid[x1][y2]+2)%3;
    grid[x2][y1]=(grid[x2][y1]+2)%3;
}

bool canTransform(vector<vector<int>>& a,const vector<vector<int>>& b,int n,int m){
    for(int i=0;i<n-1;++i){
        for(int j=0;j<m-1;++j){
            while(a[i][j]!=b[i][j]){
                applyOperation(a,i,j,i+1,j+1);
            }
        }
    }
    for(int i=0;i<n;++i){
        if(a[i][m-1]!=b[i][m-1]) return false;
    }
    for(int j=0;j<m;++j){
        if(a[n-1][j]!=b[n-1][j]) return false;
    }
    return true;
}

void solve(){
    ll n,m;cin>>n>>m;
    debug(n,m);
    vector<vector<int>> a(n,vector<int>(m,0)),b(n,vector<int>(m,0));
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
    if(canTransform(a,b,n,m)){
        yes;
    } else {
        no;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t;cin>>t;while(t--){solve();cout<<"\n";}
    return 0;
}
