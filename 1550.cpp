#include <iostream>
#include <cstring>
#include <queue>

#define MAX 10010

using namespace std;

int dist[MAX];

int main(){
	int t, a, b;
	scanf("%d", &t);
	while(t--){
		memset(dist, -1, sizeof(dist));
		scanf("%d %d", &a, &b);
		queue<int> q;
		q.push(a);
		dist[a] = 0;
		while(!q.empty()){
			int u = q.front();
			if(dist[b]!=-1) break;
			q.pop();
			int rev = 0, uu=u;
			while(uu){
				rev *= 10;
				rev += uu%10;
				uu/=10;
			}
			
			if(dist[rev]==-1){
				dist[rev] = dist[u]+1;
				q.push(rev);
			}
			if(dist[u+1]==-1){
				dist[u+1] = dist[u]+1;
				q.push(u+1);
			}
		}
		cout << dist[b] << endl;
	}
	return 0;
}
