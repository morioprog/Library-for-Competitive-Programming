class SegmentMap : public map<int_fast64_t, int_fast64_t> {
	bool flagToMergeAdjacentSegment;
	SegmentMap(bool flagToMergeAdjacentSegment) : flagToMergeAdjacentSegment(flagToMergeAdjacentSegment) {}
	auto get(int_fast64_t p) const {
		auto it = upper_bound(p);
		if (it == begin() or (--it)->second < p) return end();
		return it;
	}
	void insert(int_fast64_t l, int_fast64_t r) {
		auto itl = upper_bound(l), itr = upper_bound(r + flagToMergeAdjacentSegment);
		if (itl != begin()) {
			if ((--itl)->second < l - flagToMergeAdjacentSegment) ++itl;
		}
		if (itl != itr) {
			l = min(l, itl->first);
			r = max(r, prev(itr)->second);
			erase(itl, itr);
		}
		(*this)[l] = r;
	}
	void remove(int_fast64_t l, int_fast64_t r) {
		auto itl = upper_bound(l), itr = upper_bound(r);
		if (itl != begin()) {
			if ((--itl)->second < l) ++itl;
		}
		if (itl == itr) return;
		int tl = min(l, itl->first), tr = max(r, prev(itr)->second);
		erase(itl, itr);
		if (tl < l) (*this)[tl] = l - 1;
		if (r < tr) (*this)[r + 1] = tr;
	}
	bool same(int_fast64_t p, int_fast64_t q) const {
		const auto&& it = get(p);
		return it != end() and it->first <= q and q <= it->second;
	}
};

/*
・SegmentMap
[備考] 区間をmapで管理するやつ
[注意] 以下で扱う区間は全て閉区間
[使用例]
SegmentMap mp(flag);    // flagがtrueなら, [l, c]と[c + 1, r]をマージする
mp.get(p);              // pを含む区間を返す(存在しないならmp.end())
mp.insert(l, r);        // 閉区間[l, r]を追加する
mp.remove(l, r);        // 閉区間[l, r]を取り除く
mp.same(p, q);          // 2点p, qが同じ区間にあればtrue
*/
