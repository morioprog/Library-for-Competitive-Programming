template<typename T> using Matrix = vector< vector< T > >;
template<typename T> Matrix< T > WarshallFloyd(Graph< T > &g) {
    const auto INF = numeric_limits< T >::max() / 10;
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
                if (dist[i][k] != INF and dist[k][j] != INF) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }
    return dist;
}
template<typename T> void add_edge_to_matrix(Matrix< T > &mat, int from, int to, T weight = 1) {
    const auto INF = numeric_limits< T >::max() / 10;
    mat[from][to] = mat[to][from] = min(mat[from][to], weight);
    int vertex = mat.size();
    for (int k : {from, to}) {
        for (int i = 0; i < vertex; ++i) {
            for (int j = 0; j < vertex; ++j) {
                if (mat[i][k] != INF and mat[k][j] != INF) {
                    mat[i][j] = min(mat[i][j], mat[i][k] + mat[k][j]);
                }
            }
        }
    }
}

/*
・ワーシャルフロイド法
    > O(V ^ 3) [V:頂点数] : 全点間最短路 (WarshallFloyd())
    > O(V ^ 2)           : 辺の追加 (add_edge_to_matrix())
[備考] 全点間最短路を求めるアルゴリズム
      負閉路が存在しているかの検出も可能
        -> ある頂点vからv自身への最短路が負なら負閉路が存在
[注意] 結果を足し合わせる際, INFの大きさに注意
[使用例]
auto wf = WarshallFloyd(g);         // グラフgにおける全点間最短路
add_edge_to_matrix(wf, a, b, c);    // 隣接行列wfに, 始点a, 終点b, 重さcの辺を追加して, wfを更新
*/
