struct Point {
	ll x, y;
	bool operator<(Point p) {
		return x < p.x || (x == p.x && y < p.y);
	}
};
llu cross_product(Point O, Point A, Point B) {
	return (A.x - O.x) * (B.y - O.y)
		- (A.y - O.y) * (B.x - O.x);
	//+ve for anti clock
}
vector<Point> convex_hull(vector<Point> A) { //builds hull in anti clock order
	int n = A.size(), k = 0;
	if (n <= 3)
		return A;
	vector<Point> ans(2 * n);
	sort(A.begin(), A.end());
	for (int i = 0; i < n; ++i) { //lower hull
		while (k >= 2 && cross_product(ans[k - 2], ans[k - 1], A[i]) <= 0)
			k--; //checking for clockwise turns
		ans[k++] = A[i];
	}
	for (size_t i = n - 1, t = k + 1; i > 0; --i) { //upper hull
		while (k >= t && cross_product(ans[k - 2], ans[k - 1], A[i - 1]) <= 0)
			k--; //checking for clockwise turns
		ans[k++] = A[i - 1];
	}
	ans.resize(k - 1);
	return ans;
}
