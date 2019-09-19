/*
・トポロジカルソート
    > O(E + V) [E:辺の数, V:頂点の数]
[備考] グラフの位相的順序を求める.
[使用例]
vector<int> ts;             // トポロジカルソートの結果を格納するvector.
TopologicalSort(g, ts);     // グラフgのトポロジカルソートの結果をtsに格納. 返り値はトポロジカルソート可能か否か.
*/

template<typename T> bool TopologicalSort(const Graph< T > &g, vector<int> &order) {
    int V = g.size();
    vector<int> color(V);
    function<bool(int)> visit = [&](int v) {
        color[v] = 1;
        for (auto& e: g[v]) {
            if (color[e.to] == 2) continue;
            if (color[e.to] == 1) return false;
            if (!visit(e.to)) return false;
        }
        order.push_back(v); color[v] = 2;
        return true;
    };
    for (int i = 0; i < V; ++i) if (!color[i] and !visit(i)) return false;
    reverse(order.begin(), order.end());
    return true;
}