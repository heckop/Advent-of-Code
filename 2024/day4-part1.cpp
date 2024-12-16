#include<bits/stdc++.h>
#define int long long
using namespace std;
vector<vector<char>> v;
int get_count(int x,int y,int n,int m){
    int ans=0;
    if(y+3<m){
        if(v[x][y+1]=='M' && v[x][y+2]=='A' && v[x][y+3]=='S'){
            ans++;
        }
    }
    if(y-3>=0){
        if(v[x][y-1]=='M' && v[x][y-2]=='A' && v[x][y-3]=='S'){
            ans++;
        }
    }
    if(x+3<n){
        if(v[x+1][y]=='M' && v[x+2][y]=='A' && v[x+3][y]=='S'){
            ans++;
        }
    }
    if(x-3>=0){
        if(v[x-1][y]=='M' && v[x-2][y]=='A' && v[x-3][y]=='S'){
            ans++;
        }
    }
    if(y+3<m && x+3<n){
        if(v[x+1][y+1]=='M' && v[x+2][y+2]=='A' && v[x+3][y+3]=='S'){
            ans++;
        }
    }
    if(y+3<m && x-3>=0){
        if(v[x-1][y+1]=='M' && v[x-2][y+2]=='A' && v[x-3][y+3]=='S'){
            ans++;
        }
    }
    if(y-3>=0 && x-3>=0){
        if(v[x-1][y-1]=='M' && v[x-2][y-2]=='A' && v[x-3][y-3]=='S'){
            ans++;
        }
    }
    if(y-3>=0 && x+3<n){
        if(v[x+1][y-1]=='M' && v[x+2][y-2]=='A' && v[x+3][y-3]=='S'){
            ans++;
        }
    }
    return ans;
}
void solve() {
    int n=v.size();
    int m=v[0].size();
    int ans=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(v[i][j]=='X'){
                ans+=get_count(i,j,n,m);
            }
        }
    }
    cout<<ans<<'\n';
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    #endif

    for (int i = 0; i < 140; i++) {
        vector<char> temp;
        for (int j = 0; j < 140; j++) {
            char a;
            cin >> a;
            temp.push_back(a);
        }
        v.push_back(temp);
    }
    int _=1;
    // cin>>_;
    while(_--){
        solve();
    }
    return 0;
}
