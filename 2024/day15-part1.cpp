#include<bits/stdc++.h>
#include <cstdio>
#define int long long
using namespace std;

vector<vector<char> > v;
string comm;
inline void solve(){
    int px,py;
    for(int i=0;i<50;i++){
        for(int j=0;j<50;j++){
            if(v[i][j]=='@'){
                px=i,py=j;
            }
        }
    }
    for(int i=0;i<comm.size();i++){
        if(comm[i]=='<'){
            if(v[px][py-1]=='.'){
                v[px][py]='.';
                v[px][py-1]='@';
                py--;
                continue;
            }
            if(v[px][py-1]=='#'){
                continue;
            }
            if(v[px][py-1]=='O'){
                bool gap=0;
                int ny;
                for(int j=py-2;j>=0;j--){
                    if(v[px][j]=='#'){
                        break;
                    }
                    if(v[px][j]=='.'){
                        gap=1;
                        ny=j;
                        break;
                    }
                }
                if(gap){
                    v[px][py]='.';
                    v[px][py-1]='@';
                    v[px][ny]='O';
                    py--;
                }
            }
        }
        if(comm[i]=='>'){
            if(v[px][py+1]=='.'){
                v[px][py]='.';
                v[px][py+1]='@';
                py++;
                continue;
            }
            if(v[px][py+1]=='#'){
                continue;
            }
            if(v[px][py+1]=='O'){
                bool gap=0;
                int ny;
                for(int j=py+2;j<50;j++){
                    if(v[px][j]=='#'){
                        break;
                    }
                    if(v[px][j]=='.'){
                        gap=1;
                        ny=j;
                        break;
                    }
                }
                if(gap){
                    v[px][py]='.';
                    v[px][py+1]='@';
                    v[px][ny]='O';
                    py++;
                }
            }
        }
        if(comm[i]=='^'){
            if(v[px-1][py]=='.'){
                v[px][py]='.';
                v[px-1][py]='@';
                px--;
                continue;
            }
            if(v[px-1][py]=='#'){
                continue;
            }
            if(v[px-1][py]=='O'){
                bool gap=0;
                int ny;
                for(int j=px-2;j>=0;j--){
                    if(v[j][py]=='#'){
                        break;
                    }
                    if(v[j][py]=='.'){
                        gap=1;
                        ny=j;
                        break;
                    }
                }
                if(gap){
                    v[px][py]='.';
                    v[px-1][py]='@';
                    v[ny][py]='O';
                    px--;
                }
            }
        }
        if(comm[i]=='v'){
            if(v[px+1][py]=='.'){
                v[px][py]='.';
                v[px+1][py]='@';
                px++;
                continue;
            }
            if(v[px+1][py]=='#'){
                continue;
            }
            if(v[px+1][py]=='O'){
                bool gap=0;
                int ny;
                for(int j=px+2;j<50;j++){
                    if(v[j][py]=='#'){
                        break;
                    }
                    if(v[j][py]=='.'){
                        gap=1;
                        ny=j;
                        break;
                    }
                }
                if(gap){
                    v[px][py]='.';
                    v[px+1][py]='@';
                    v[ny][py]='O';
                    px++;
                }
            }
        }
    }
    int ans=0;
    for(int i=0;i<50;i++){
        for(int j=0;j<50;j++){
            if(v[i][j]=='O'){
                ans+=(100*i+j);
            }
        }
    }
    cout<<ans;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r" , stdin);
    // freopen("out.txt", "w", stdout);
    #endif
    for(int i=0;i<50;i++){
        vector<char> temp;
        for(int j=0;j<50;j++){
            char a;cin>>a;
            temp.push_back(a);
        }
        v.push_back(temp);
    }
    cin>>comm;
    int _=1;
    // cin>>_;
    while(_--){
        solve();
        //cout<<'\n';
    }
}
