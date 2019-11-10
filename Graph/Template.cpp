template<typename T> struct Edge {
    int from, to;
    T weight;
    Edge() : from(0), to(0), weight(0) {}
    Edge(int f, int t, T w) : from(f), to(t), weight(w) {}
};
template<typename T> using Edges = vector< Edge< T > >;
template<typename T> using Graph = vector< Edges< T > >;
template<typename T> void     add_edge(Graph< T > &g, int from, int to, T w = 1) { g[from].emplace_back(from, to, w); g[to].emplace_back(to, from, w); }
template<typename T> void      add_arc(Graph< T > &g, int from, int to, T w = 1) { g[from].emplace_back(from, to, w); }
template<typename T> void add_to_edges(Edges< T > &e, int from, int to, T w = 1) { e.emplace_back(from, to, w); }

/*
・グラフ用テンプレート
    > Dijkstra
    > BellmanFord
    > WarshallFloyd
    > Kruskal
[応用] 単一終点最短路問題は, すべての有向辺を逆向きに張り替えると, 単一始点最短路問題に帰着できる.
[使用例]
Graph<int> g(V);                // 頂点数V, 重さの型がintのグラフを宣言
add_edge(g, a, b, c);           // グラフgに, 始点a, 終点b, 重さcの無向辺を追加
add_arc(g, a, b, c);            // グラフgに, 始点a, 終点b, 重さcの有向辺を追加
add_to_edges(edges, a, b, c);   // 辺集合edgesに, 始点a, 終点b, 重さcの辺を追加
*/
