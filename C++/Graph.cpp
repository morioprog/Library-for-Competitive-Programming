/*
・グラフ
  > Dijkstra
  > BellmanFord
  > WarshallFloyd
[使用例]
Graph<int> g(N);    // 頂点数N, 重さの型がintのグラフを宣言
add_edge(g,a,b,c);  // グラフgに, aからbへの重さcの無向辺を追加
add_arc(g,a,b,c);   // グラフgに, aからbへの重さcの有向辺を追加
*/

template<typename T> struct Edge {
  int from, to;
  T weight;
  Edge() : from(0), to(0), weight(0) {}
  Edge(int f, int t, T w) : from(f), to(t), weight(w) {}
};
template<typename T> using Edges = vector< Edge< T > >;
template<typename T> using Graph = vector< Edges< T > >;
template<typename T> void add_edge(Graph< T > &g, int from, int to, T w = 1) { g[from].emplace_back(from,to,w); g[to].emplace_back(to,from,w); }
template<typename T> void  add_arc(Graph< T > &g, int from, int to, T w = 1) { g[from].emplace_back(from,to,w); }

/*
・ダイクストラ法
  > O(ElogV) [E:辺の数, V:頂点の数]
[備考] 負辺の存在しないグラフに対する単一始点全点間最短路を求めるアルゴリズム
[使用例]
auto dij = Dijkstra(g,s);     // グラフgにおける, 始点sからの最短路
*/

template<typename T> vector< T > Dijkstra(Graph<T> &g, int from) {
  const auto INF = numeric_limits< T >::max();
  vector< T > dist(g.size(), INF);
  dist[from] = 0;
  using Pi = pair< T, int >;
  priority_queue< Pi, vector< Pi >, greater< Pi > > que;
  que.emplace(dist[from], from);
  while ( !que.empty() ) {
    T weight; int idx;
    tie(weight, idx) = que.top(); que.pop();
    if (dist[idx] < weight) continue;
    for (auto &e : g[idx]) {
      auto next_weight = weight + e.weight;
      if (dist[e.to] <= next_weight) continue;
      dist[e.to] = next_weight;
      que.emplace(dist[e.to], e.to);
    }
  }
  return dist;
}

/*
・ベルマンフォード法
  > O(EV) [E:辺の数, V:頂点の数]
[備考] グラフ(負辺が存在してもよい)に対する単一始点全点間最短路を求めるアルゴリズム
      負閉路が存在しているかの判定も可能 -> 存在していたら空列を返す
[使用例]
Edges<int> edges;                     // 全ての辺 (重さ: int)
add_to_edges(edges,a,b,c);            // 辺集合edgesに, 始点a, 終点b, 重さcの辺を追加
auto bf = BellmanFord(edges,V,s);     // 辺edges, 頂点数Vのグラフにおける, 始点sからの最短路
*/

template<typename T> void add_to_edges(Edges< T > &e, int from, int to, T w = 1) { e.emplace_back(from,to,w); }
template<typename T> vector< T > BellmanFord(Edges< T > &edges, int vertex, int from) {
  const auto INF = numeric_limits< T >::max();
  vector< T > dist(vertex, INF);
  dist[from] = 0;
  for (int i = 0; i < vertex - 1; ++i) {
    for (auto &e : edges) {
      if (dist[e.from] == INF) continue;
      dist[e.to] = min(dist[e.to], dist[e.from] + e.weight);
    }
  }
  for (auto &e : edges) {
    if (dist[e.from] == INF) continue;
    if (dist[e.from] + e.weight < dist[e.to]) return vector< T >();
  }
  return dist;
}

/*
・ワーシャルフロイド法
  > O(V^3) [V:頂点数] (WarshallFloyd())
  > O(V^2) : 辺の追加 (add_edge_to_matrix())
[備考] 全点間最短路を求めるアルゴリズム
      負閉路が存在しているかの検出も可能
        -> ある頂点vからv自身への最短路が負なが負閉路が存在
[使用例]
auto wf = WarshallFloyd(g);      // グラフgにおける全点間最短路
add_edge_to_matrix(wf,a,b,c);    // 隣接行列wfに, 始点a, 終点b, 重さcの辺を追加して, wfを更新
*/

template<typename T> using Matrix = vector< vector< T > >;
template<typename T> Matrix< T > WarshallFloyd(Graph< T > &g) {
  const auto INF = numeric_limits< T >::max();
  int vertex = g.size();
  Matrix< T > dist(vertex, vector< T >(vertex, INF));
  for (int i = 0; i < vertex; ++i) dist[i][i] = 0;
  for (int i = 0; i < vertex; ++i) {
    for (auto &e : g[i]) {
      dist[e.from][e.to] = min(dist[e.from][e.to], e.weight);
    }
  }
  for (int k = 0; k < vertex; ++k) {
    for (int i = 0; i < vertex; ++i) {
      for (int j = 0; j < vertex; ++j) {
        if (dist[i][k] != INF && dist[k][j] != INF) {
          dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
        }
      }
    }
  }
  return dist;
}
template<typename T> void add_edge_to_matrix(Matrix< T > &mat, int from, int to, T weight = 1) {
  const auto INF = numeric_limits< T >::max();
  mat[from][to] = mat[to][from] = min(mat[from][to], weight);
  int vertex = mat.size();
  for (int k : {from, to}) {
    for (int i = 0; i < vertex; ++i) {
      for (int j = 0; j < vertex; ++j) {
        if (mat[i][k] != INF && mat[k][j] != INF) {
          mat[i][j] = min(mat[i][j], mat[i][k] + mat[k][j]);
        }
      }
    }
  }
}
