#include<bits/stdc++.h>
#define int long long int
using namespace std;

vector<pair<int,int> > pos,vel;
inline void solve(){
    int br=101,ln=103;
    for(int j=0;j<100;j++){
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
    }
    // cout<<vel[0].first<<' '<<vel[0].second<<'\n';
    int a=0,b=0,c=0,d=0;
    for(int i=0;i<pos.size();i++){
        if(pos[i].first<=49 && pos[i].second<=50){
            a++;
        }
        if(pos[i].first<=49 && pos[i].second>=52){
            c++;
        }
        if(pos[i].first>=51 && pos[i].second>=52){
            d++;
        }
        if(pos[i].first>=51 && pos[i].second<=50){
            b++;
        }
    }
    cout<<a<<' '<<b<<' '<<c<<' '<<d<<'\n';
    cout<<a*b*c*d<<'\n';
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
