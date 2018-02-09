#define fi first
#define se second
#define mp make_pair

/* Sliding window structure which allows us to get minimum element in O(1) */
struct min_queue {
	int sum, t;

	min_queue() {
		sum = t = 0;
	}

	queue<pair<int, int> > q;
	deque<pair<int, int> > dq;

	void push(int x) {
		while (dq.size() && dq.back().fi + sum >= x) dq.pop_back();
		q.push(mp(x - sum, t));
		dq.push_back(mp(x - sum, t++));
	}

	void pop() {
		if (q.front().se == dq.front().se) dq.pop_front();
		q.pop();
	}

	int get_min() {
		return dq.front().fi + sum;
	}

	void add(int x) {
		sum += x;
	}

};