#include <iostream>
#include <cstring>
#define MAX 510
#include <queue>

using namespace std;

typedef pair<int, int> ii;
ii ne[] {ii(1, 0), ii(0,1), ii(-1, 0), ii(0,-1)};

char grid[MAX][MAX];
int dist[MAX][MAX];
int x, y;

int main(){
	int n, m, d;
	while(scanf("%d %d", &n, &m), n|m){
		memset(grid, 0, sizeof grid);
		memset(dist, -1, sizeof dist);
		for(int i=1; i<=n; i++)
			scanf("%s", &grid[i][1]);
		ii rj;
		for(int i=1; i<=n; i++){
			for(int j=1; j<=m; j++){
				if(grid[i][j]=='.') {
					rj = make_pair(i, j);
					break;
				}
			}
		}
		d = 0;
		queue<ii> q;
		q.push(rj);
		dist[rj.first][rj.second] = 0;
		while(!q.empty()){
			int i = q.front().first, j = q.front().second;
			q.pop();
			for(auto h : ne){
				if(grid[i+h.first][j+h.second]=='.' && dist[i+h.first][j+h.second]==-1){
					dist[i+h.first][j+h.second] = dist[i][j]+1;
					if(dist[i+h.first][j+h.second] > d){
						x = i+h.first;
						y = j+h.second;
						d = dist[i+h.first][j+h.second];
					}
					q.push(make_pair(i+h.first, j+h.second));
				}
			}
		}
		memset(dist, -1, sizeof dist);
		q.push(make_pair(x, y));
		dist[x][y] = 0;
		while(!q.empty()){
			int i = q.front().first, j = q.front().second;
			q.pop();
			for(auto h : ne){
				if(grid[i+h.first][j+h.second]=='.' && dist[i+h.first][j+h.second]==-1){
					dist[i+h.first][j+h.second] = dist[i][j]+1;
					if(dist[i+h.first][j+h.second] > d){
						x = i+h.first;
						y = j+h.second;
						d = dist[i+h.first][j+h.second];
					}
					q.push(make_pair(i+h.first, j+h.second));
				}
			}
		}
		printf("%d\n", d);
	}
	return 0;
}
