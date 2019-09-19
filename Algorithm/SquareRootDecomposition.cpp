const int bucketSize = 400
function<int(int, int)> query = [&](int l, int r) {
    int ret = 0;
    for (int x = l; x < r;) {
        int bi = x / bucketSize;
        if (l <= bi * bucketSize and (bi + 1) * bucketSize <= r) {
            // バケット
            x += bucketSize;
        } else {
            // 余った部分
            ++x;
        }
    }
    return ret;
};
