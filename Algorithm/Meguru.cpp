long long ok = $1, ng = $2;
while (abs(ok - ng) > 1) {
    long long mid = (ok + ng) >> 1;
    if (check(mid)) {
        ok = mid;
    } else {
        ng = mid;
    }
}
