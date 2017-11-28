int v[N];
int seg[4*N];
int lazy[4*N];

void propagate(int p, int l, int r) {
	seg[p] += lazy[p];
	
	if (l != r) {
		lazy[2*p] += lazy[p];
		lazy[2*p + 1] += lazy[p];
	}

	lazy[p] = 0;
}

int query(int p, int l, int r, int a, int b) {
	propagate(p, l, r);
	if (r < a || l > b) return inf;
	if (l >= a && r <= b) return seg[p];
	int mid = (l + r) / 2;
	return min(query(2*p, l, mid, a, b), query(2*p + 1, mid + 1, r, a, b));
}

void update(int p, int l, int r, int a, int b, ll val) {
	propagate(p, l, r);
	if (r < a || l > b) return;
	if (l >= a && r <= b) {
		lazy[p] += val;
		propagate(p, l, r);
		return;
	}

	int mid = (l + r) / 2;
	update(2*p, l, mid, a, b, val);
	update(2*p + 1, mid + 1, r, a, b, val);
	seg[p] = min(seg[2*p], seg[2*p + 1]);
}

void build(int p, int l, int r) {
	if (l == r) return void(seg[p] = v[l]);
	int m = (l + r) / 2;
	build(2*p, l, m);
	build(2*p + 1, m + 1, r);
	seg[p] = min(seg[2*p], seg[2*p + 1]);
}

int main() {
	//build(1, 1, n);
	//update(1, 1, n, l, r, val);

	return 0;
}
