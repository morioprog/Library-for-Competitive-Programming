template<typename T> vector< T > BellmanFord(Edges< T > &edges, int vertex, int from) {
    const auto INF = numeric_limits< T >::max() / 10;
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
・ベルマンフォード法
    > O(E * V) [E:辺の数, V:頂点の数]
[備考] グラフ(負辺が存在してもよい)に対する単一始点全点間最短路を求めるアルゴリズム
      負閉路が存在しているかの判定も可能 -> 存在していたら空列を返す
[注意] 結果を足し合わせる際, INFの大きさに注意
[使用例]
Edges<int> edges;                       // 全ての辺 (重さ: int)
add_to_edges(edges, a, b, c);           // 辺集合edgesに, 始点a, 終点b, 重さcの辺を追加
auto bf = BellmanFord(edges, V, s);     // 辺edges, 頂点数Vのグラフにおける, 始点sからの最短路
*/
