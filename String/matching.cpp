/* String matching algorithms in O(n) */

const int N = 1000007; //1e6

int z[N], pi[N];

void preffix(string& s) {
	pi[0] = 0;

	for (int i = 1; i < s.size(); i++) {
		pi[i] = pi[i-1];

		while (pi[i] > 0 && s[i] != s[pi[i]]) {
			pi[i] = pi[pi[i] -1];
		}
		if (s[i] == s[pi[i]]) pi[i]++;
	}
}

void z_function(string& s) {
	z[0] = 0;
	int l, r, n = s.size();
	l = r = 0;

	for (int i = 1; i < n; i++) {
		if (i > r) l = r = i;

		z[i] = min(z[i-l], r - i);
		while (i + z[i] < n && s[i + z[i]] == s[z[i]]) {
			z[i]++;
			l = i;
			r = i + z[i];
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	string s;
	cin >> s;

	preffix(s);
	z_function(s);

	return 0;
}