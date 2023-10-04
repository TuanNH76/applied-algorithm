#include<bits/stdc++.h>
using namespace std;

int n,m,r,c;
int dx[5]={0,1,-1,0,0};
int dy[5]={0,0,0,1,-1};

int visited[1000][1000], a[1000][1000];
int main(){
    cin >>n >>m >>r >>c;
    for(int i= 1 ; i<=n; i ++){
        for(int j=1; j <= m ; j++){
            cin >> a[i][j];
            visited[i][j] = 0;
        }
    }

    queue<pair<int,int>> q;
    visited[r][c] = 1;
    q.push(make_pair(r,c));
    while(!q.empty()){
        int curx= q.front().first;
        int cury = q.front().second;
        q.pop();
        for(int i =0;i<=4;i++){
            int newx = curx + dx[i];
            int newy = cury + dy[i];
            if(visited[newx][newy] || a[newx][newy]) continue;

            if(newx == 1 || newy == 1 || newx == n || newy == m){
                cout << visited[curx][cury] +1 ;
                return 0;
            }
            q.push(make_pair(newx,newy));
            visited[newx][newy] = visited[curx][cury] + 1 ;
        }
    }

    cout << -1;
    return 0;
}