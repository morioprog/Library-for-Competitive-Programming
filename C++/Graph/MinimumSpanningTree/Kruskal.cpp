/*
・Kruskal法
    > O(ElogV) [E:辺の数, V:頂点の数]
[備考] 最小全域木を求めるアルゴリズム.
      UnionFindで, 閉路を作らないように辺を重みが小さい順に加えていく.
[注意] UnionFindを上で定義しておくこと.
[使用例]
Edges<int> edges;           // 全ての辺 (重さ: int)
add_to_edges(edges,a,b,c);  // 辺集合edgesに, 始点a, 終点b, 重さcの辺を追加
Kruskal(edges,V);           // 辺edges, 頂点数Vのグラフにおける最小全域木の重さ
*/

template<typename T> T Kruskal(Edges< T > &edges, int V) {
    sort(begin(edges), end(edges), [](const Edge< T > &a, const Edge< T > &b) {
        return (a.weight < b.weight);
    });
    UnionFind tree(V);
    T ret = 0;
    for (auto &e : edges) if (tree.unite(e.from, e.to)) ret += e.weight;
    return ret;
}