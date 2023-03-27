#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define int long long
#define F first
#define S second
#define pb push_back
using namespace std;
using namespace __gnu_pbds;
const int N = 1e6 + 5, MOD = 1e9 + 7;
// can change to pair<int, int> also
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>

void solve(){
	/*
  ordered_set <set_name>
  functionalities:
  <set_name>.insert(<element>);
  <set_name>.find_by_order(k); == It returns to an iterator 
  to the kth element (counting from zero) in the set in O(logn) time
  <set_name>.order_of_key(k) == It returns to the number of items 
  that are strictly smaller than our item k in O(logn) time.
  */
}

int32_t main(){
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);cout.tie(NULL);
	int t = 1;
	cin >> t;
	while(t--)
		solve();
	return 0;
}
