#include<bits/stdc++.h>
// #define int long long
using namespace std;

vector<int> dx={0,0,-1,1};
vector<int> dy={1,-1,0,0};
int area=0;
vector<vector<char> > exmat;
int get_side(int i, int j){
    //outside corners
    i++,j++;
    int res=0;
    if(exmat[i+1][j] !=exmat[i][j] && exmat[i][j+1]!=exmat[i][j]){
        res++;
    }
    if(exmat[i+1][j] !=exmat[i][j] && exmat[i][j-1]!=exmat[i][j]){
        res++;
    }
    if(exmat[i-1][j] !=exmat[i][j] && exmat[i][j+1]!=exmat[i][j]){
        res++;
    }
    if(exmat[i-1][j] !=exmat[i][j] && exmat[i][j-1]!=exmat[i][j]){
        res++;
    }
    if(exmat[i-1][j] ==exmat[i][j] && exmat[i][j-1]==exmat[i][j] && exmat[i-1][j-1]!=exmat[i][j]){
        res++;
    }
    if(exmat[i-1][j] ==exmat[i][j] && exmat[i][j+1]==exmat[i][j] && exmat[i-1][j+1]!=exmat[i][j]){
        res++;
    }
    if(exmat[i+1][j] ==exmat[i][j] && exmat[i][j-1]==exmat[i][j] && exmat[i+1][j-1]!=exmat[i][j]){
        res++;
    }
    if(exmat[i+1][j] ==exmat[i][j] && exmat[i][j+1]==exmat[i][j] && exmat[i+1][j+1]!=exmat[i][j]){
        res++;
    }
    return res;
}
int dfs(int i, int j, vector<vector<int> > &vis, vector<vector<char> > &mat, vector<pair<int,int> > &xx, vector<pair<int,int> > &yy, int n, int m){
    area++;
    int peri=0;
    vis[i][j]=1;
    peri+=get_side(i,j);
    for(int k=0;k<4;k++){
        int nx=i+dx[k];
        int ny=j+dy[k];
        if(nx>=0 && ny>=0 && nx<n && ny<m && !vis[nx][ny]){
            if(mat[nx][ny]==mat[i][j]){
                peri+=dfs(nx,ny,vis,mat,xx,yy,n,m);
            }
        }
    }
    return peri;
}
inline void solve(){
    int n,m;cin>>n>>m;
    vector<vector<char> > v(n,vector<char>(m));
    exmat= vector<vector<char> >(n+2,vector<char>(m+2));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>v[i][j];
        }
    }
    for(int i=0;i<n+2;i++){
        exmat[i][0]='.';
    }
    for(int i=0;i<m+2;i++){
        exmat[0][i]='.';
    }
    for(int i=0;i<n+2;i++){
        exmat[m+1][0]='.';
    }
    for(int i=0;i<m+2;i++){
        exmat[n+1][i]='.';
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            exmat[i][j]=v[i-1][j-1];
        }
    }
    vector<vector<int> > vis(n,vector<int>(m,0));
    int ans=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(!vis[i][j]){
                area=0;
                vector<pair<int,int> > xx(n,{0,0});
                vector<pair<int,int> > yy(m,{0,0});
                int peri=dfs(i,j,vis,v, xx, yy, n, m);
                cout<<v[i][j]<<' '<<area<<' '<<peri<<'\n';
                ans+=area*peri;
            }
        }
    }
    cout<<ans<<'\n';
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // #ifndef ONLINE_JUDGE
    // freopen("in.txt", "r" , stdin);
    // freopen("out.txt", "w", stdout);
    // #endif
    int _=1;
    // cin>>_;
    while(_--){
        solve();
        //cout<<'\n';
    }
}
