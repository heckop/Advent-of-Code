#include<bits/stdc++.h>
#include <cstdio>
#define int long long
using namespace std;

vector<vector<char> > v;

pair<int,char> get_dir(char cur,int nx,int ny,int x,int y){
    int price=0;
    if(cur=='W' || cur=='E'){
        int dx=nx-x;
        int dy=ny-y;
        if(dy>0){
            if(cur=='W'){
                price+=2*1000;
                return make_pair(price,'E');
            }
            else{
                return make_pair(price,cur);
            }
        }
        if(dy<0){
            if(cur=='E'){
                price+=2*1000;
                return make_pair(price,'W');
            }
            else{
                return make_pair(price,cur);
            }
        }
        if(dx>0){
            price+=1000;
            return make_pair(price,'S');
        }
        if(dx<0){
            price+=1000;
            return make_pair(price,'N');
        }
    }
    if(cur=='N' || cur=='S'){
        int dx=nx-x;
        int dy=ny-y;
        if(dx>0){
            if(cur=='N'){
                price+=2*1000;
                return make_pair(price,'S');
            }
            else{
                return make_pair(price,cur);
            }
        }
        if(dx<0){
            if(cur=='S'){
                price+=2*1000;
                return make_pair(price,'N');
            }
            else{
                return make_pair(price,cur);
            }
        }
        if(dy>0){
            price+=1000;
            return make_pair(price,'E');
        }
        if(dy<0){
            price+=1000;
            return make_pair(price,'W');
        }
    }
}

inline void solve(){
    vector<int> dx={0,0,-1,1};
    vector<int> dy={1,-1,0,0};
    int n=v.size();
    int m=v[0].size();
    priority_queue<tuple<int,int,int,char>,vector<tuple<int,int,int,char>>,greater<tuple<int,int,int,char>>> pq;
    int x,y;
    int rx,ry;
    for(int i=0;i<v.size();i++){
        for(int j=0;j<v[0].size();j++){
            if(v[i][j]=='S'){
                x=i,y=j;
            }
            if(v[i][j]=='E'){
                rx=i,ry=j;
            }
        }
    }
    pq.push({0,x,y,'E'});
    vector<vector<int> > dis(n,vector<int>(m,1e9));
    dis[x][y]=0;
    while(!pq.empty()){
        auto [d,px,py,dir]=pq.top();
        pq.pop();
        for(int i=0;i<4;i++){
            int nx=px+dx[i];
            int ny=py+dy[i];
            if(nx>=0 && ny>=0 && nx<n && ny<m){
                if(v[nx][ny]!='#'){
                    auto [price,nxdir]=get_dir(dir,nx,ny,px,py);
                    price++;
                    if(dis[nx][ny]>d+price){
                        dis[nx][ny]=d+price;
                        pq.push({dis[nx][ny],nx,ny,nxdir});
                    }
                }
            }
        }
    }
    cout<<dis[rx][ry]<<'\n';
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r" , stdin);
    // freopen("out.txt", "w", stdout);
    #endif
    for(int i=0;i<141;i++){
        vector<char> temp;
        for(int j=0;j<141;j++){
            char a;cin>>a;
            temp.push_back(a);
        }
        v.push_back(temp);
    }
    int _=1;
    // cin>>_;
    while(_--){
        solve();
        //cout<<'\n';
    }
}
