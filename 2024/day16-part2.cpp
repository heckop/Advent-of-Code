#include<bits/stdc++.h>
#define int long long
using namespace std;
vector<vector<char>> v;

vector<int> dx = {0, -1, 0, 1};
vector<int> dy = {1, 0, -1, 0};
const vector<char> dir_chars = {'E', 'N', 'W', 'S'};

void print_map(vector<vector<char>> & v){
    for(int i=0;i<v.size();i++){
        for(int j=0;j<v[0].size();j++){
            cout<<v[i][j];
        }
        cout<<'\n';
    }
}
pair<int, char> get_dir(char cur, int nx, int ny, int x, int y) {
    int price = 0;
    int cur_idx = find(dir_chars.begin(), dir_chars.end(), cur) - dir_chars.begin();

    int move_dir = -1;
    for (int i = 0; i < 4; i++) {
        if (nx == x + dx[i] && ny == y + dy[i]) {
            move_dir = i;
            break;
        }
    }

    if (move_dir == -1) return {INT_MAX, cur}; // Invalid move

    int rotations = (move_dir - cur_idx + 4) % 4;
    if (rotations > 2) rotations = 4 - rotations;
    price += rotations * 1000;

    return {price, dir_chars[move_dir]};
}

void solve() {
    int n = v.size();
    int m = v[0].size();
    int start_x = -1, start_y = -1;
    int end_x = -1, end_y = -1;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (v[i][j] == 'S') start_x = i, start_y = j;
            if (v[i][j] == 'E') end_x = i, end_y = j;
        }
    }

    vector<vector<vector<int>>> dist(n, vector<vector<int>>(m, vector<int>(4, INT_MAX)));

    priority_queue<tuple<int,int,int,char>, vector<tuple<int,int,int,char>>, greater<>> pq;

    int start_dir_idx = find(dir_chars.begin(), dir_chars.end(), 'E') - dir_chars.begin();
    dist[start_x][start_y][start_dir_idx] = 0;
    pq.push({0, start_x, start_y, 'E'});
    int ans;
    while (!pq.empty()) {
        auto [d, px, py, dir] = pq.top();
        pq.pop();

        int cur_dir_idx = find(dir_chars.begin(), dir_chars.end(), dir) - dir_chars.begin();

        if (px == end_x && py == end_y) {
            ans=d;
            break;
        }

        for (int i = 0; i < 4; i++) {
            int nx = px + dx[i];
            int ny = py + dy[i];

            if (nx < 0 || ny < 0 || nx >= n || ny >= m || v[nx][ny] == '#') continue;

            auto [rotate_price, new_dir] = get_dir(dir, nx, ny, px, py);
            if (rotate_price == INT_MAX) continue;

            int new_cost = d + rotate_price + 1;
            int new_dir_idx = find(dir_chars.begin(), dir_chars.end(), new_dir) - dir_chars.begin();

            if (new_cost < dist[nx][ny][new_dir_idx]) {
                dist[nx][ny][new_dir_idx] = new_cost;
                pq.push({new_cost, nx, ny, new_dir});
            }
        }
    }
    cout<<ans<<'\n';
    vector<vector<vector<int>>> rev_dist(n, vector<vector<int>>(m, vector<int>(4, INT_MAX)));
    priority_queue<tuple<int,int,int,char>, vector<tuple<int,int,int,char>>, greater<>> pq1;
    for(int i=0;i<4;i++){
        rev_dist[end_x][end_y][i]=0;
        pq1.push({0,end_x,end_y,dir_chars[i]});
    }
    while (!pq1.empty()) {
        auto [d, px, py, dir] = pq1.top();
        pq1.pop();

        int cur_dir_idx = find(dir_chars.begin(), dir_chars.end(), dir) - dir_chars.begin();

        for (int i = 0; i < 4; i++) {
            int nx = px + dx[i];
            int ny = py + dy[i];

            if (nx < 0 || ny < 0 || nx >= n || ny >= m || v[nx][ny] == '#') continue;

            auto [rotate_price, new_dir] = get_dir(dir, nx, ny, px, py);
            if (rotate_price == INT_MAX) continue;

            int new_cost = d + rotate_price + 1;
            int new_dir_idx = find(dir_chars.begin(), dir_chars.end(), new_dir) - dir_chars.begin();

            if (new_cost < rev_dist[nx][ny][new_dir_idx]) {
                rev_dist[nx][ny][new_dir_idx] = new_cost;
                pq1.push({new_cost, nx, ny, new_dir});
            }
        }
    }
    map<int,int> flip_dir;
    flip_dir[0]=2;
    flip_dir[2]=0;
    flip_dir[1]=3;
    flip_dir[3]=1;
    int count=0;
    vector<vector<char>> fin_map=v;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(v[i][j]!='#'){
                for(int k=0;k<4;k++){
                    for(int l=0;l<4;l++){
                        if(dist[i][j][k]+rev_dist[i][j][l]==ans){
                            fin_map[i][j]='O';
                            count++;
                        }
                    }
                }
            }
        }
    }
    print_map(fin_map);
    cout<<count<<'\n';
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    #endif

    for (int i = 0; i < 15; i++) {
        vector<char> temp;
        for (int j = 0; j < 15; j++) {
            char a;
            cin >> a;
            temp.push_back(a);
        }
        v.push_back(temp);
    }

    solve();
    return 0;
}
