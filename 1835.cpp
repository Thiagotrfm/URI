#include <iostream>
#define MAX 110
#include <vector>
#include <cstring>

using namespace std;
int states[MAX];
vector<int> v[MAX];

void bfs(int a){
  states[a]=1;
  for(auto it : v[a]){
    if(states[it]==0)
      bfs(it);
  }
}
int main(){
  int t, n, m, a, b;
  scanf("%d", &t);
  for(int o=1; o<=t; o++){
    scanf("%d", &n);
    memset(states, 0, sizeof states);
    for(int i=0; i<MAX; i++) v[i].clear();
    scanf("%d", &m);
    while(m--){
      scanf("%d %d", &a, &b);
      v[a].push_back(b);
      v[b].push_back(a);
    }
    int c = 0;
    for(int k=1; k<=n; k++){
      if(states[k]==0){ 
        bfs(k);
        c++;
      }
    }
    if(c==1) printf("Caso #%d: a promessa foi cumprida\n", o);
		else printf("Caso #%d: ainda falta(m) %d estrada(s)\n", o, c-1);
  } 
  return 0; 
}   

