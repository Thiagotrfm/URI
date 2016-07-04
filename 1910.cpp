#include <iostream>
#include <cstring>
#include <queue>

#define MAX 350000

using namespace std;

int dist[MAX], forb[MAX];
int main(){
	int o, d, k, a, i;
	while(scanf("%d %d %d", &o, &d, &k), o | d | k){
		memset(dist, -1, sizeof dist);
		memset(forb, 0, sizeof forb);
		queue<int> q;
		for(i=0; i<k; i++){
			scanf("%d", &a);
			forb[a] = 1;
		}
		dist[o] = 0;
		q.push(o);
		while(!q.empty()){
			if(dist[d]!=-1) break;
			int u = q.front();
			q.pop();
			if(!forb[u-1] && u-1 > 0 && dist[u-1]==-1){
				dist[u-1] = dist[u]+1;
				q.push(u-1);
			}
			if(!forb[u+1] && u+1 <= 100000 && dist[u+1]==-1){
				dist[u+1] = dist[u]+1;
				q.push(u+1);
			}
			if(u%2==0 && !forb[u/2] && dist[u/2]==-1){
				dist[u/2] = dist[u]+1;
				q.push(u/2);
			}
			if(u*2<=100000 && !forb[u*2] && dist[u*2]==-1){
				dist[u*2] = dist[u]+1;
				q.push(u*2);
			}
			if(u*3<=100000 && !forb[u*3] && dist[u*3]==-1){
				dist[u*3] = dist[u]+1;
				q.push(u*3);
			}
		}
		printf("%d\n", dist[d]);
	}
	return 0;
}
