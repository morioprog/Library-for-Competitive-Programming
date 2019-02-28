/*
・Dinic法
  > O(EV^2) [E:辺の数, V:頂点の数]
[備考] 最大流を求めるアルゴリズム.
      最大流は最小カットと一致する(最大フロー最小カット定理).
      「燃やす埋める問題」や「全ての頂点を二色に塗り分ける問題」などは最小カットに帰着できる.
[参考] http://yosupo.hatenablog.com/entry/2015/03/31/134336
[使用例]
Dinic<int> dnc(N);                // 頂点数Nのグラフを用意.
dnc.add_edge(from, to, cap);      // 頂点fromから頂点toへ容量capの有向辺を足す.
dnc.max_flow(s, t);               //
*/

template<typename T> struct Dinic {
  struct edge {
    int to;
    T cap;
    int rev;
  };

  const T INF;
  vector< vector< edge > > graph;
  vector< T > min_cost;
  vector< int > iter;

  Dinic(int n) : INF(numeric_limits< T >::max()) {
    graph.resize(n);
  }

  void add_edge(int from, int to, T cap) {
    graph[from].push_back((edge) {to, cap, (int) graph[  to].size()});
    graph[  to].push_back((edge) {from, 0, (int) graph[from].size() - 1});
  }

  bool bfs(int s, int t) {
    min_cost.assign(graph.size(), -1);
    queue<int> que;
    min_cost[s] = 0;
    que.push(s);
    while (!que.empty()) {
      int p = que.front();
      que.pop();
      for (auto &e : graph[p]) {
        if (e.cap > 0 && min_cost[e.to] == -1) {
          min_cost[e.to] = min_cost[p] + 1;
          que.push(e.to);
        }
      }
    }
    return (min_cost[t] != -1);
  }

  T dfs(int idx, const int t, T flow) {
    if (idx == t) return (flow);
    for (int &i = iter[idx]; i < graph[idx].size(); i++) {
      edge &e = graph[idx][i];
      if (e.cap > 0 && min_cost[idx] < min_cost[e.to]) {
        T d = dfs(e.to, t, min(flow, e.cap));
        if (d > 0) {
          e.cap -= d;
          graph[e.to][e.rev].cap += d;
          return (d);
        }
      }
    }
    return (0);
  }

  T max_flow(int s, int t) {
    T flow = 0;
    while (bfs(s, t)) {
      iter.assign(graph.size(), 0);
      T f = 0;
      while ((f = dfs(s, t, INF)) > 0) {
        flow += f;
      }
    }
    return (flow);
  }
};

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
ff.max_flow(s, t);                // 頂点sから頂点tへ最大流を流す.
*/

template<typename T> struct FordFulkerson {
  struct edge {
    int to;
    T cap;
    int rev;
  };

  vector< vector< edge > > graph;
  vector< int > used;
  const T INF;
  int timestamp;

  FordFulkerson(int n) : INF(numeric_limits< T >::max()), timestamp(0) {
    graph.resize(n);
    used.assign(n, -1);
  }

  void add_edge(int from, int to, T cap) {
    graph[from].emplace_back((edge) {to, cap, (int) graph[  to].size()});
    graph[  to].emplace_back((edge) {from, 0, (int) graph[from].size() - 1});
  }

  T dfs(int idx, const int t, T flow) {
    if (idx == t) return flow;
    used[idx] = timestamp;
    for (auto &e : graph[idx]) {
      if (e.cap > 0 && used[e.to] != timestamp) {
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
    for (T f; (f = dfs(s, t, INF)) > 0; timestamp++) {
      flow += f;
    }
    return flow;
  }
};
