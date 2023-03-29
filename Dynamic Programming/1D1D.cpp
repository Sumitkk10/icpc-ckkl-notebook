/*Let w(i,j) be the cost function.
for all i<=j, w(i,j)+w(i+1,j+1)<=w(i+1,j)+w(i,j+1)
From a practical point of view, we don't need to prove that w satisfies such an inequality,
it's easier to just list out a few values of w and check.
If we can't use CHT for this kind of DP optimization, GENERALLY they are solvable using this trick.
Complexity: O(nlogn)*/
int w(int l, int r){
	return b[l] * a[r];
}
int dp[n + 1];
	dp[1] = 0;
  // dp[i] = min(dp[j] + b[j] * a[i], dp[i]);
	vector<pair<int, int> > v; // (start pos, best k ( current idx) )
	v.push_back({0, 1});
	for(int x = 2; x <= n; ++x){
		pair<int, int> now = {x + 1, 0};
		pair<int, int> cur = *(--lower_bound(v.begin(), v.end(), now));
		int k = cur.S;
		// cout << x << ' ' << k << endl;
		dp[x] = dp[k] + w(k, x);
		for(int i = (int)v.size() - 1; i >= 0; i--) {
		  int y = v[i].first, oldk = v[i].second;
		  if (y > x && dp[x] + w(x, y) < dp[oldk] + w(oldk, y)) v.pop_back();
		  else {
		    int l = y + 1, r = n + 1;
		    while (l < r) {
		      int mid = (l + r) / 2;
		      if (dp[x] + w(x, mid) < dp[oldk] + w(oldk, mid)) r = mid;
		      else l = mid + 1;
		    }
		    if (r != n + 1) v.push_back(make_pair(r, x));
		    break;
		  }
		}
		if (v.size() == 0) v.push_back(make_pair(0, x));
	}
