#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

int main() {
	ios::sync_with_stdio(false);

	ordered_set st;
	st.insert(3);
	cout << *st.find_by_order(0) << endl;

	return 0;
}
