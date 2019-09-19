/*
・Ford-Fulkerson法
    > O(EF) [E:辺の数, F:最大フロー]
[備考] 最大流を求めるアルゴリズム.
      最大流は最小カットと一致する(最大フロー最小カット定理).
      「燃やす埋める問題」や「全ての頂点を二色に塗り分ける問題」などは最小カットに帰着できる.
[参考] http://yosupo.hatenablog.com/entry/2015/03/31/134336
[使用例]
FordFulkerson<int> ff(N);         // 頂点数Nのグラフを用意.
ff.add_edge(from, to, cap);       // 頂点fromから頂点toへ容量capの有向辺を足す.
ff.max_flow(s, t);                // 頂点sから頂点tへの最大流.
*/

template<typename T> struct FordFulkerson {
    struct edge {
        int to;
        T cap;
        int rev;
    };
    vector< vector< edge > > graph;
    vector<int> used;
    const T INF;
    int timestamp;
    FordFulkerson(int n) : INF(numeric_limits< T >::max()), timestamp(0) {
        graph.resize(n);
        used.assign(n, -1);
    }
    void add_edge(int from, int to, T cap) {
        graph[from].emplace_back((edge) {to, cap, (int)graph[  to].size()});
        graph[  to].emplace_back((edge) {from, 0, (int)graph[from].size() - 1});
    }
    T dfs(int idx, const int t, T flow) {
        if (idx == t) return flow;
        used[idx] = timestamp;
        for (auto &e : graph[idx]) {
            if (e.cap > 0 and used[e.to] != timestamp) {
                T d = dfs(e.to, t, min(flow, e.cap));
                if (d > 0) {
                    e.cap -= d;
                    graph[e.to][e.rev].cap += d;
                    return d;
                }
            }
        }
        return 0;
    }
    T max_flow(int s, int t) {
        T flow = 0;
        for (T f; (f = dfs(s, t, INF)) > 0; timestamp++) flow += f;
        return flow;
    }
};
