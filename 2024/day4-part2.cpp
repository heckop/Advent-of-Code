#include<bits/stdc++.h>
#define int long long
using namespace std;
vector<vector<char>> v;
int get_count(int x,int y,int n,int m){
    int ans=0;
    if(x-1>=0 && x+1<n && y-1>=0 && y+1<m){
        bool b1=(v[x-1][y-1]=='M' && v[x+1][y+1]=='S') || (v[x+1][y+1]=='M' && v[x-1][y-1]=='S');
        bool b2=(v[x-1][y+1]=='M' && v[x+1][y-1]=='S') || (v[x+1][y-1]=='M' && v[x-1][y+1]=='S');
        ans+=(b1&&b2);
    }
    // cout<<x<<' '<<y<<' '<<ans<<'\n';
    return ans;
}
void solve() {
    int n=v.size();
    int m=v[0].size();
    int ans=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(v[i][j]=='A'){
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
