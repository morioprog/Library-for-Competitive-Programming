/*
・最小費用流
    > O(FElogV) [E:辺の数, V:頂点の数]
[備考] 最小費用流を求めるアルゴリズム.
[参考] 辺の数が多い場合は, O(UCV^2) [U:容量合計, C:費用合計] のアルゴリズムもある.
        (http://www.prefield.com/algorithm/graph/primal_dual.html)
[使用例]
Primal_Dual pd(N);                  // 頂点数Nのグラフを用意.
pd.add_edge(from, to, cap, cost);   // 頂点fromから頂点toへ, 容量cap, 単位コストcostの有向辺を用意.
pd.min_cost_flow(from, to, flow);   // 頂点fromから頂点toへ, 流量flowを流す際のコスト.
*/

struct PrimalDual {
    const int INF = 1 << 30;
    typedef pair<int, int> P;
    struct edge {
        int to, cap, cost, rev;
    };
    vector< vector< edge > > graph;
    vector< int > potential, min_cost, prevv, preve;
    PrimalDual(int V) : graph(V) {}
    void add_edge(int from, int to, int cap, int cost) {
        graph[from].push_back((edge) {to, cap,  cost, (int)graph[to].size()});
        graph[  to].push_back((edge) {from, 0, -cost, (int)graph[from].size() - 1});
    }
    int min_cost_flow(int s, int t, int f) {
        int V = graph.size(), ret = 0;
        priority_queue< P, vector< P >, greater< P > > que;
        potential.assign(V, 0);
        preve.assign(V, -1);
        prevv.assign(V, -1);
        while (f > 0) {
            min_cost.assign(V, INF);
            que.push(P(0, s));
            min_cost[s] = 0;
            while (not que.empty()) {
                P p = que.top(); que.pop();
                if (min_cost[p.second] < p.first) continue;
                for (int i = 0; i < (int)graph[p.second].size(); i++) {
                    edge &e = graph[p.second][i];
                    int nextCost = min_cost[p.second] + e.cost + potential[p.second] - potential[e.to];
                    if (e.cap > 0 and min_cost[e.to] > nextCost) {
                        min_cost[e.to] = nextCost;
                        prevv[e.to] = p.second, preve[e.to] = i;
                        que.push(P(min_cost[e.to], e.to));
                    }
                }
            }
            if (min_cost[t] == INF) return -1;
            for (int v = 0; v < V; v++) potential[v] += min_cost[v];
            int addflow = f;
            for (int v = t; v != s; v = prevv[v]) {
                addflow = min(addflow, graph[prevv[v]][preve[v]].cap);
            }
            f -= addflow;
            ret += addflow * potential[t];
            for (int v = t; v != s; v = prevv[v]) {
                edge &e = graph[prevv[v]][preve[v]];
                e.cap -= addflow;
                graph[v][e.rev].cap += addflow;
            }
        }
        return ret;
    }
};
