template <typename T> bool isBipartiteGraph(const Graph< T > &g) {
    int V = g.size();
    vector<int> color(V, 0);
    bool ret = true;
    function<void(int, int)> dfs = [&](int i, int clr) {
        if (color[i] != 0) return;
        color[i] = clr;
        for (auto& e: g[i]) {
            if (color[e.to] == 0) dfs(e.to, -clr);
            else if (color[e.to] == clr) ret = false;
        }
    };
    dfs(0, 1);
    return ret;
    int cnt = 0;
    for (auto& e: color) if (e == 1) ++cnt;
    return ret ? -1 : cnt;
}

/*
・二部グラフの判定
    > O(E+V) [E:辺の数, V:頂点の数]
[備考] 二部グラフならtrueを返す.
[使用例] isBipartiteGraph(g);
[その他] 二部グラフだった際に, 片方の集合の大きさが知りたい場合は, return retを削除して, intを返すようにする.
        その場合は, 二部グラフならばその集合の大きさを, そうでない場合は-1を返す.
*/
