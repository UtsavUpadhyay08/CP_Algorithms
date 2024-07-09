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

class TrieNode {
public:
    char data;
    ll wc,we;					// Word end, Word Count
    TrieNode* child[26];

    TrieNode(char c):data(c),we(0),wc(0){
        fori(i,0,26){
            child[i]=nullptr;
        }
    }
};

class Trie {
private:
    TrieNode* root;

public:
    Trie() {
        root = new TrieNode('/');
    }

    TrieNode* getNode(char c) {
        return new TrieNode(c);
    }

    void insert(string& s) {
        TrieNode* curr = root;
        ll ind=s.size();
        for(char ch:s){
        	--ind;
            ll index = ch - 'a';
            if(curr->child[index] == nullptr) {
                curr->child[index] = getNode(ch);
            }
            if(ind==0){
            	// debug(ch,curr->child[index]->data,curr->child[index]->we);
            	curr->child[index]->we++;
            }
            curr->child[index]->wc += 1;
            curr = curr->child[index];
        }
    }

    bool search(string& s) {
        TrieNode* curr = root;
        ll ind=s.size();
        for (char ch : s) {
        	--ind;
            ll index = ch - 'a';
            if ((curr->child[index] == nullptr) || ((ind==0) && (curr->child[index]->we == 0)) || (curr->child[index]->wc == 0)) {
                return false;
            }
            // debug(ch,curr->we,curr->wc)
            curr = curr->child[index];
        }
        return true;
    }

    void Triedelete(string& s) {
        if (search(s)) {
            TrieNode* curr = root;
            for(char ch : s) {
                ll index = ch - 'a';
                curr->child[index]->wc -= 1;
                curr->child[index]->we -= 1;
                curr = curr->child[index];
            }
        }
    }

    ll countPrefix(const string& s) {
        TrieNode* curr = root;
        for (char ch : s) {
            ll index = ch - 'a';
            if (curr->child[index] == nullptr || curr->child[index]->wc == 0) {
                return 0; // No string with given prefix is present
            }
            curr = curr->child[index];
        }
        return curr->wc;
    }
};

//Trie var_name; initializes and value can be inserted in it

void solve(){
	ll n;cin>>n;
	// vll a(n);for(auto &x:a) cin>>x;
	// string s;cin>>s;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    Trie t;
    string s="abc";
    t.insert(s);
    s="abb";
    t.insert(s);
    s="abd";
    t.insert(s);
    s="ab";
    // debug(s)
    cout<<t.search(s);
	// solve();
    // ll t;cin>>t;while(t--){solve();cout<<"\n";}
    return 0;
}