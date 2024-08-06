//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;
#ifdef UTSAV
#include "handle_debug.hpp"
#define debug(...) cout<<'[';debug_print(#__VA_ARGS__, __VA_ARGS__);cout<<"]\n";
#else
#define debug(...)
#endif

// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    int maxLength(vector<int> a) {
        // code here
        vector<vector<int>> pre(a.size(),vector<int>(32,0));
        for(int i=0;i<a.size();i++){
            for(int j=0;j<32;j++){
                if(((1<<j)&a[i])==(1<<j)){
                    pre[i][j]++;
                }
                if(i!=0) pre[i][j]+=pre[i-1][j];
            }
        }
        int ans=0,n=a.size();
        for(int i=0;i<n;i++){
            int l=i+1,r=n-1;
            while(l<=r){
                int mid=l+(r-l)/2,num=0;
                for(int j=0;j<32;j++){
                    int vl=pre[mid][j];
                    if(i!=0) vl=vl-pre[i-1][j];
                    if(vl>0){
                        num+=(1<<j);
                    }
                }
                // cout<<i;
                // debug(i,mid,num,l,r);
                if(((num+1)&num)==0){
                    ans=max(ans,mid-i+1);
                    l=mid+1;
                }
                else r=mid-1;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        Solution ob;
        cout << ob.maxLength(a) << endl;
    }
    return 0;
}
// } Driver Code Ends