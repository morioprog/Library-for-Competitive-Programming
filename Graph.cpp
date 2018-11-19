using Weight = int;
using Flow = int;
struct Edge {
    int src, dst;
    Weight weight;
    Flow cap;
    Edge() : src(0), dst(0), weight(0) {}
    Edge(int s, int d, Weight w) : src(s), dst(d), weight(w) {}
};
using Edges = vector<Edge>;
using Graph = vector<Edges>;
using Array = vector<Weight>;
using Matrix = vector<Array>;
void add_edge(Graph &g,int a,int b,Weight w=1){g[a].emplace_back(a,b,w);g[b].emplace_back(b,a,w);}
void add_arc(Graph &g,int a,int b,Weight w=1){g[a].emplace_back(a,b,w);}
Matrix WarshallFloyd(const Graph &g) {
    auto const INF = std::numeric_limits<Weight>::max()/8;
    int n = g.size();
    Matrix d(n,Array(n,INF));
    REP(i,n) d[i][i] = 0;
    REP(i,n) for(auto &e : g[i]) d[e.src][e.dst]=min(d[e.src][e.dst],e.weight);
    REP(k,n) REP(i,n) REP(j,n) if(d[i][k]!=INF && d[k][j]!=INF) d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
    return d;
}
vector<Weight> Dijkstra(const Graph &g,int s) {
    const Weight INF = numeric_limits<Weight>::max()/8;
    using state = tuple<Weight,int>;
    priority_queue<state> q;
    vector<Weight> dist(g.size(),INF);
    dist[s] = 0;
    q.emplace(0,s);
    while (q.size()) {
        Weight d;
        int v;
        tie(d,v) = q.top(); q.pop();
        d *= -1;
        /* if(v == t) return d; */
        if (dist[v]<d) continue;
        for (auto &e : g[v]) {
            if (dist[e.dst] > dist[v] + e.weight) {
                dist[e.dst] = dist[v] + e.weight;
                q.emplace(-dist[e.dst], e.dst);
            }
        }
    }
    return dist;
}
