int_fast64_t ok = $1, ng = $2;
while (abs(ok - ng) > 1) {
    int_fast64_t mid = (ok + ng) >> 1;
    if (check(mid)) {
        ok = mid;
    } else {
        ng = mid;
    }
}
