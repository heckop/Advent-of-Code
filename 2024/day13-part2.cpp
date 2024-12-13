#include<bits/stdc++.h>
#define int long long int
using namespace std;

vector<pair<int,int> > ba,bb,pr;

inline void solve(){
    int ans=0;
    for(int i=0;i<ba.size();i++){
        int kq=(bb[i].second*pr[i].first-bb[i].first*pr[i].second);
        int pq=(ba[i].first*pr[i].second-ba[i].second*pr[i].first);
        int den=(ba[i].first*bb[i].second-ba[i].second*bb[i].first);
        // cout<<kq<<' '<<pq<<' '<<den<<'\n';
        if(kq%den==0 && pq%den==0){
            // cout<<"hello\n";
            ans+=((kq/den)*3LL)+(pq/den);
        }
    }
    cout<<ans<<'\n';
}
/* Important note, trim the input so that it appears like this:
45 11
23 63
17967 17271

12 35
42 26
13022 9764

It can be done using multicursor, a simple task
*/
signed main() {
    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r" , stdin);
    // freopen("out.txt", "w", stdout);
    #endif
    for(int i=0;i<320;i++){
        int a1,a2,b1,b2,c1,c2;
        cin>>a1>>a2>>b1>>b2>>c1>>c2;
        c1+=10000000000000;
        c2+=10000000000000;
        ba.emplace_back(a1,a2);
        bb.emplace_back(b1,b2);
        pr.emplace_back(c1,c2);
    }
    int _=1;
    // cin>>_;
    while(_--){
        solve();
    }
}
