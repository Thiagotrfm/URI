#include <iostream>
#include <vector>
#include <cstring>

#define MAX1 30
using namespace std;

int states[MAX1];
vector<int> v[MAX1];
vector<string> res[MAX1];
int out[MAX1];

void bfs(int a){
  states[a] = 1;
  for(auto it : v[a])
    if(states[it]==0)
      bfs(it);
}


int main(){
  int viz, n;
  while(scanf("%d", &n), n){
    memset(out, 0, sizeof out);
    for(int i=0; i<=MAX1; i++){
      v[i].clear();
			res[i].clear();
		}
    for(int i=1; i<=n; i++){
      while(scanf("%d", &viz), viz){
        v[i].push_back(viz);
        out[i]++;
      }
    }
    int p, t1, t2;
    char a1[MAX1], a2[MAX1], a3[MAX1];
    
    while(scanf("%d", &p), p){ 
      memset(states, 0, sizeof states);
			scanf("%d %d", &t1, &t2);
      bfs(p);
			scanf("%s %s %s", a1, a2, a3);
			for(int i=1; i<=n; i++){
				if(states[i]==0) res[i].push_back(a1);
				else{
					if(out[i]<t1) res[i].push_back(a1);
					else if(out[i] < t2) res[i].push_back(a2);
					else res[i].push_back(a3);
				}
			}
    }
		char name[MAX1];
		for(int i=1; i<=n; i++){
			scanf("%s", name);
			cout << name << ": ";
			for(auto it : res[i]){
				cout << it << " ";
			}
			cout << endl;
		}
  }
  return 0;
}

