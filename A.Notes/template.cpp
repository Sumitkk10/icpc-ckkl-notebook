#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC target("avx2, sse, sse2, sse3, ssse3, sse4, popcnt, abm, mmx, avx, tune=native")
#define int long long
#define F first
#define S second
#define pb push_back
using namespace std;
using namespace __gnu_pbds;
const int N = 1e6 + 5, MOD = 1e9 + 7;
// can change to pair<int, int> also
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int genNum(int l, int r) {
    return l + rand() % (r - l + 1);
}
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31); }
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM); }
};
void solve(){
/* ordered_set <set_name>
  functionalities:
  <set_name>.insert(<element>);
  <set_name>.find_by_order(k); == It returns to an iterator 
  to the kth element (counting from zero) in the set in O(logn) time
  <set_name>.order_of_key(k) == It returns to the number of items 
  that are strictly smaller than our item k in O(logn) time. */
  // unordered_map<long long, int, custom_hash> safe_map;
  // shuffle(res.begin(), res.end(), rng);
}
int32_t main(){
	srand(chrono::steady_clock::now().time_since_epoch().count());
  	ios_base::sync_with_stdio(0);
  	cin.tie(NULL);cout.tie(NULL);
	int t = 1;
	cin >> t;
	while(t--)
		solve();
	return 0;
}
