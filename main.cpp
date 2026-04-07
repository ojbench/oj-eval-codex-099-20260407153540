#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int m,n;
    if(!(cin>>m>>n)) return 0;
    vector<vector<int>> a(m, vector<int>(n));
    for(int i=0;i<m;++i){
        for(int j=0;j<n;++j){
            cin>>a[i][j];
        }
    }
    vector<vector<int>> vis(m, vector<int>(n, 0));
    long long best = 0;
    int dx[4] = {1,-1,0,0};
    int dy[4] = {0,0,1,-1};
    for(int i=0;i<m;++i){
        for(int j=0;j<n;++j){
            if(a[i][j] > 0 && !vis[i][j]){
                long long sum = 0;
                deque<pair<int,int>> q;
                q.push_back({i,j});
                vis[i][j] = 1;
                while(!q.empty()){
                    int x = q.front().first;
                    int y = q.front().second;
                    q.pop_front();
                    sum += a[x][y];
                    for(int d=0; d<4; ++d){
                        int nx = x + dx[d];
                        int ny = y + dy[d];
                        if(nx>=0 && nx<m && ny>=0 && ny<n && !vis[nx][ny] && a[nx][ny] > 0){
                            vis[nx][ny] = 1;
                            q.push_back({nx,ny});
                        }
                    }
                }
                if(sum > best) best = sum;
            }
        }
    }
    cout << best << '\n';
    return 0;
}
