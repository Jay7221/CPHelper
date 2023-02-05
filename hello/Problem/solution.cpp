#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<ll> dp;
vector<vector<pair<int, ll> >> graph;
ll dfs(int u)
{
	if(dp[u] != -1)
	{
		return dp[u];
	}
	ll ans = 0;
	for(auto [v, w] : graph[u])
	{
		ans = max(ans, w + dfs(v));
	}
	return dp[u] = ans;
}
void solve(int t)
{
	int n, m;
	cin >> n >> m;
	graph.assign(n, vector<pair<int, ll>>());
	dp.assign(n, -1ll);
	int T = 72;
	for(int i = 0; i < m; ++i)
	{
		int u, v;
		ll w;
		cin >> u >> v;
		assert((u <= n));
		assert((u >= 1));
		assert((v <= n));
		assert((v >= 1));
		--u, --v;
		cin >> w;
		graph[u].push_back({v, w});
	}
	cout << dfs(0) << '\n';
}
int main()
{
	int T;
	cin >> T;
	for(int t = 1; t <= T; ++t)
	{
		solve(t);
	}
	return 0;
}
