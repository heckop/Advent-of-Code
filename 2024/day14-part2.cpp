#include<bits/stdc++.h>
#define int long long int
using namespace std;

vector<pair<int,int> > pos,vel;
bool check(){
    vector<vector<int> > grid(101,vector<int>(103,0));
    for(int i=0;i<pos.size();i++){
        grid[pos[i].first][pos[i].second]++;
    }
    for(int i=0;i<101;i++){
        for(int j=0;j<103;j++){
            if(grid[i][j]>1){
                return 0;
            }
        }
    }
    return 1;
}
inline void solve(){
    int br=101,ln=103;
    for(int j=0;j<120000;j++){
        for(int i=0;i<pos.size();i++){
            if(vel[i].first>0){
                if(pos[i].first+vel[i].first<101){
                    pos[i].first=pos[i].first+vel[i].first;
                }
                else{
                    int rem=100-pos[i].first;
                    pos[i].first=vel[i].first-rem-1;
                }
            }
            else{
                if(pos[i].first+vel[i].first>=0){
                    pos[i].first=pos[i].first+vel[i].first;
                }
                else{
                    pos[i].first=101-(abs(vel[i].first)-pos[i].first);
                }
            }
            if(vel[i].second>0){
                if(pos[i].second+vel[i].second<103){
                    pos[i].second=pos[i].second+vel[i].second;
                }
                else{
                    int rem=102-pos[i].second;
                    pos[i].second=vel[i].second-rem-1;
                }
            }
            else{
                if(pos[i].second+vel[i].second>=0){
                    pos[i].second=pos[i].second+vel[i].second;
                }
                else{
                    pos[i].second=103-(abs(vel[i].second)-pos[i].second);
                }
            }
        }
        if(check()){
            cout<<j+1<<'\n';
        }
    }

}
//format the input using multicursor feature
signed main() {
    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r" , stdin);
    // freopen("out.txt", "w", stdout);
    #endif
    for(int i=0;i<500;i++){
        int x,y,vx,vy;cin>>x>>y>>vx>>vy;
        pos.emplace_back(x,y);
        vel.emplace_back(vx,vy);
    }
    int _=1;
    // cin>>_;
    while(_--){
        solve();
    }
}
