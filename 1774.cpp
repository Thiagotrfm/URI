//Kruskall Algorithm

#include <iostream>
#include <queue>

using namespace std;
using ii = pair<int, int>;
using edge = pair<int, ii>;
using vi = vector<int>;

class UFDS {
  int m_count;
  vi m_parents, m_rank;

public:

  UFDS(int V) : m_count(V), m_parents(V + 1, 0), m_rank(V + 1, 0){
    for(int i=1; i<=V; ++i){
      m_parents[i] = i;
    }
  }

  int find_set(int u){
    return m_parents[u] == u ? u : (m_parents[u] = find_set(m_parents[u]));
  }

  bool same_set(int u, int v){
    return find_set(u) == find_set(v);
  }

  void union_set(int u, int v){
    if(same_set(u, v)) return;

    int p = find_set(u), q = find_set(v);

    if(m_rank[p] >= m_rank[q])
      m_parents[q] = p;
    else
      m_parents[p] = q;

    if(m_rank[p] == m_rank[q]) ++m_rank[p];
    --m_count;
  }

  int count() const { return m_count; }
};

priority_queue<edge> pq;

int kruskall(int v){
  UFDS ufds(v);
  int D = 0;
  while(!pq.empty()){
    auto e = pq.top();
    pq.pop();

    int w = -e.first;
    int u = e.second.first;
    int v = e.second.second;

    if(not ufds.same_set(u, v)){
      ufds.union_set(u, v);
      D += w;
    }
  }
  return D;
}

int main(){
  int m, n, x, y, z;

  while(scanf("%d %d", &m, &n)!=EOF){
    for(int i=0; i<n; i++){
      scanf("%d %d %d", &x, &y, &z);
      pq.push(edge(-z, ii(x, y)));
    }

    printf("%d\n", kruskall(m));
  }
  return 0;
}

