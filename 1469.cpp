#include <iostream>
#include <cstring>
#define MAX 510
#include <vector>

using namespace std;

int mini, emp[MAX], states[MAX];
vector<int> adj[MAX];

void dfs(int a){
	states[a] = 1;
	int tam = adj[a].size();
	for(int i=0; i<tam; i++){
		if(states[adj[a][i]]==0){
			mini = min(mini, emp[adj[a][i]]);
			dfs(adj[a][i]);
		}
	}
	
}

int main(){
	int m, n, l, a, b;
	while(scanf("%d %d %d", &n, &m, &l)!=EOF){
		memset(adj, 0, sizeof adj);
		memset(states, 0, sizeof states);
		for(int i=1; i<=n; i++)
			scanf("%d", &emp[i]);
		for(int i=0; i<m; i++){
			scanf("%d %d\n", &a, &b);
			adj[b].push_back(a);
		}
		char c;
		for(int i=0; i<l; i++){
			scanf(" %c", &c);
			if(c=='P'){
				scanf("%d", &a);
				mini = 101;
				memset(states, 0, sizeof states);
				dfs(a);
				if(mini==101) printf("*\n");
				else printf("%d\n", mini);	
			}
			if(c=='T'){
				scanf("%d %d", &a, &b);
				swap(adj[a], adj[b]);
				for(int k=1; k<=n; k++){
					int tam = adj[k].size();
					for(int p=0; p<tam; p++){
						if(adj[k][p]==a) adj[k][p] = b;
						else if(adj[k][p]==b) adj[k][p] = a;
					}
				}
			}
		}
	}
	return 0;
}
