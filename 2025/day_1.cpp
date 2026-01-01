#include<bits/stdc++.h>
using namespace std;
#define int long long
vector<string> inputs;

void read(){
    string line;
    while(cin>>line){
        inputs.push_back(line);
        // cout<<line;
    }
}
void solve() {
    read();
    int cur = 50;
    int ans=0;
    for(int i=0;i<inputs.size();i++){
        string temp = inputs[i];
        if (temp[0] == 'R'){
            int num = stoi(temp.substr(1));
            ans+=(num/100);
            num%=100;
            if(cur+num>99){
                cur = (cur+num - 100);
                ans++;
            }
            else cur+=num;
        }
        else{
            int num = stoi(temp.substr(1));
            ans+=(num/100);
            num%=100;
            if(cur-num<0){
                num -= cur;
                if(cur>0) ans++;
                cur = 100 - num;
            }
            else cur-=num;
            ans+=(cur==0);
        }
    }
    cout<<"Password is: "<<ans<<'\n';
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r" , stdin);
    // freopen("out.txt", "w", stdout);
    #endif
    read();
    int _=1;
    // cin>>_;
    while(_--){
        solve();
        //cout<<'\n';
    }
}
