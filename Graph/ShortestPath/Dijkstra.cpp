template<typename T> vector< T > Dijkstra(Graph< T > &g, int from) {
    const auto INF = numeric_limits< T >::max() / 10;
    vector< T > dist(g.size(), INF);
    dist[from] = 0;
    using P = pair< T, int >;
    priority_queue< P, vector< P >, greater< P > > que;
    que.emplace(dist[from], from);
    while (not que.empty()) {
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
・ダイクストラ法
    > O(ElogV) [E:辺の数, V:頂点の数]
[備考] 負辺の存在しないグラフに対する単一始点全点間最短路を求めるアルゴリズム
[注意] 結果を足し合わせる際, INFの大きさに注意
[使用例] auto dij = Dijkstra(g, s);     // グラフgにおける, 始点sからの最短路
*/
