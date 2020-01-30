def print_prefix(l):
    print('\t\t"prefix": [')
    for i in l:
        print('\t\t\t"{}",'.format(i))
    print('\t\t],')

def print_body(l):
    print('\t\t"body": [')
    for i in l:
        print('\t\t\t"{}",'.format(i))
    print('\t\t],')

def print_library(title, prefix, body):
    print('\t"{}": {{'.format(title))
    print_prefix(prefix)
    print_body(body)
    print('\t},')

def get_body(path):
    body = []
    with open(path) as f:
        for s_line in f:
            s = s_line.rstrip()
            s = s.replace("\\n","\\\\\\\\n")
            s = s.replace('"','\\"')
            s = s.replace('\\ ','\\\\ ')
            s = s.replace('\\_', '\\\\_')
            body.append(s)
    return body

# [title, prefixes, path]
libraries = [
    [
        "Template",
        ["template"],
        "Template/Main.cpp"
    ],
    [
        "Template(short)",
        ["template"],
        "Template/Short.cpp"
    ],
    [
        "めぐる式二分探索",
        ["meguru"],
        "Algorithm/Meguru.cpp"
    ],
    [
        "平方分割",
        ["heihoubunkatu", "square root decomposition"],
        "Algorithm/SquareRootDecomposition.cpp"
    ],
    [
        "高速フーリエ変換による畳み込み",
        ["convolution", "fastfouriertransform"],
        "Convolution/FastFourierTransform.cpp"
    ],
    [
        "1次元累積和",
        ["cumulativesum", "imos", "accumulate"],
        "DataStructure/CumulativeSum/CumulativeSum1D.cpp"
    ],
    [
        "2次元累積和",
        ["cumulativesum2D", "imos", "accumulate"],
        "DataStructure/CumulativeSum/CumulativeSum2D.cpp"
    ],
    [
        "セグメント木",
        ["data structure", "segment tree"],
        "DataStructure/SegmentTree/SegmentTree.cpp"
    ],
    [
        "遅延セグメント木",
        ["data structure", "segment tree", "lazy segment tree"],
        "DataStructure/SegmentTree/LazySegmentTree.cpp"
    ],
    [
        "Segment Tree Beats",
        ["data structure", "segment tree", "beats"],
        "DataStructure/SegmentTree/SegmentTreeBeats.cpp"
    ],
    [
        "Queue Aggregation",
        ["data structure", "queue aggregation", "sliding window aggregation"],
        "DataStructure/SlidingWindowAggregation/QueueAggregation.cpp"
    ],
    [
        "UnionFind木",
        ["data structure", "unionfind"],
        "DataStructure/UnionFind/UnionFind.cpp"
    ],
    [
        "重み付きUnionFind木",
        ["data structure", "unionfind", "omomituki unionfind"],
        "DataStructure/UnionFind/WeightedUnionFind.cpp"
    ],
    [
        "Binary Indexed Tree",
        ["data structure", "binary indexed tree"],
        "DataStructure/BinaryIndexedTree.cpp"
    ],
    [
        "Segment Map",
        ["data structure", "segment map", "map"],
        "DataStructure/SegmentMap.cpp"
    ],
    [
        "Sparse Table",
        ["data structure", "sparse table"],
        "DataStructure/SparseTable.cpp"
    ],
    [
        "Wavelet Matrix",
        ["data structure", "wavelet matrix"],
        "DataStructure/WaveletMatrix.cpp"
    ],
    [
        "グラフの宣言",
        ["graph"],
        "Graph/Template.cpp"
    ],
    [
        "二部グラフの判定",
        ["graph", "bipartite", "nibugurahu"],
        "Graph/BipartiteGraph/BipartiteGraphCheck.cpp"
    ],
    [
        "二部グラフの最大マッチング",
        ["graph", "bipartite", "nibugurahu", "matching"],
        "Graph/BipartiteGraph/BipartiteMatching.cpp"
    ],
    [
        "最大流 Dinic O(EV^2)",
        ["graph", "dinic", "maximum flow", "flow"],
        "Graph/MaximumFlow/Dinic.cpp"
    ],
    [
        "最大流 FordFulkerson O(EF)",
        ["graph", "fordfulkerson", "maximum flow", "flow"],
        "Graph/MaximumFlow/FordFulkerson.cpp"
    ],
    [
        "最小費用流 PrimalDual O(FElogV)",
        ["graph", "primal dual", "min cost flow", "flow"],
        "Graph/MinCostFlow/PrimalDual.cpp"
    ],
    [
        "最小全域木 Kruskal O(ElogV)",
        ["graph", "kruskal", "tree", "minimim spanning tree"],
        "Graph/MinimumSpanningTree/Kruskal.cpp"
    ],
    [
        "トポロジカルソート O(E + V)",
        ["graph", "topological sort"],
        "Graph/Other/TopologicalSort.cpp"
    ],
    [
        "BellmanFord O(EV)",
        ["graph", "bellmanford"],
        "Graph/ShortestPath/BellmanFord.cpp"
    ],
    [
        "Dijkstra O(ElogV)",
        ["graph", "dijkstra"],
        "Graph/ShortestPath/Dijkstra.cpp"
    ],
    [
        "WarshallFloyd O(V^3)",
        ["graph", "warshallfloyd"],
        "Graph/ShortestPath/WarshallFloyd.cpp"
    ],
    [
        "HeavyLightDecomposition / LCA",
        ["graph", "heavylightdecomposition", "lowestcommonancestor"],
        "Graph/HeavyLightDecomposition/HeavyLightDecomposition.cpp"
    ],
    [
        "組み合わせ (逆元)",
        ["math", "combination", "inverse"],
        "Math/Combination/Inverse.cpp"
    ],
    [
        "組み合わせ (パスカルの三角形)",
        ["math", "combination", "pascal"],
        "Math/Combination/Pascal.cpp"
    ],
    [
        "約数列挙 O(√n)",
        ["math", "divisor", "prime"],
        "Math/Prime/Divisor.cpp"
    ],
    [
        "エラトステネスの篩 O(NloglogN)",
        ["math", "eratosthenes", "prime"],
        "Math/Prime/Eratosthenes.cpp"
    ],
    [
        "素数判定 O(√n)",
        ["math", "prime"],
        "Math/Prime/PrimeCheck.cpp"
    ],
    [
        "素因数分解(約数の個数) O(√n)",
        ["math", "prime", "divisor"],
        "Math/Prime/PrimeFactor.cpp"
    ],
    [
        "行列演算",
        ["math", "matrix"],
        "Math/Matrix/Matrix.cpp"
    ],
    [
        "F_2上の行列演算",
        ["math", "matrix", "bit"],
        "Math/Matrix/BitMatrix.cpp"
    ],
    [
        "ModInt",
        ["math", "modint"],
        "Math/Modint.cpp"
    ],
    [
        "ローリングハッシュ",
        ["string", "rolling hash"],
        "String/RollingHash.cpp"
    ],
    [
        "Suffix Array",
        ["string", "suffix array"],
        "String/SuffixArray.cpp"
    ],
    [
        "座標圧縮 O(NlogN)",
        ["compression", "zaatu"],
        "Other/Compression.cpp"
    ],
    [
        "文字列と整数同士の変換",
        ["conversion", "string", "integer"],
        "Other/Conversion.cpp"
    ],
    [
        "サイコロ",
        ["dice"],
        "Other/Dice.cpp"
    ],
    [
        "ランレングス圧縮",
        ["groupby", "run length compression"],
        "Other/Groupby.cpp"
    ],
    [
        "転倒数",
        ["math", "inversion number", "tentousuu"],
        "Other/InversionNumber.cpp"
    ],
    [
        "LimitInt",
        ["math", "limitint"],
        "Other/LimitInt.cpp"
    ],
    [
        "多倍長整数 / 浮動小数点数",
        ["multiprecision", "tabaichou"],
        "Other/MultiPrecision.cpp"
    ],
]

print('{')
for library in libraries:
    title, prefixes, path = library
    body = get_body(path)
    print_library(title, prefixes, body)
print('}')
