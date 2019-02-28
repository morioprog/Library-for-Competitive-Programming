/*
・二部グラフの最大マッチング
  > O(EV) [E:辺の数, V:頂点の数]
[備考] 最大流のアルゴリズムを用いて求める.
[応用] 最大マッチングは, 最小点被覆と一致(Mとおく).
      最大安定集合(最大独立集合)は, 最小辺被覆と(V-M)で一致.
[参考] https://qiita.com/drken/items/e805e3f514acceb87602
      https://qiita.com/drken/items/7f98315b56c95a6181a4
[使用例]
Bipartite_Matching bip(N);      // 頂点数Nのグラフを用意.
bip.add_edge(from, to);         // 頂点fromから頂点toへの有向辺を足す.
bip.bipartite_matching();       // 最大マッチングを求める.
*/

struct Bipartite_Matching {
  vector< vector< int > > graph;
  vector< int > match, alive, used;
  int timestamp;

  Bipartite_Matching(int n) : timestamp(0) {
    graph.resize(n);
    alive.assign(n, 1);
    used.assign(n, 0);
    match.assign(n, -1);
  }

  void add_edge(int u, int v) {
    graph[u].push_back(v);
    graph[v].push_back(u);
  }

  bool dfs(int v) {
    used[v] = timestamp;
    for (int i = 0; i < graph[v].size(); i++) {
      int u = graph[v][i], w = match[u];
      if (alive[u] == 0) continue;
      if (w == -1 || (used[w] != timestamp && dfs(w))) {
        match[v] = u;
        match[u] = v;
        return true;
      }
    }
    return false;
  }

  int bipartite_matching() {
    int ret = 0;
    for (int i = 0; i < graph.size(); i++) {
      if (alive[i] == 0) continue;
      if (match[i] == -1) {
        ++timestamp;
        ret += dfs(i);
      }
    }
    return ret;
  }
};
