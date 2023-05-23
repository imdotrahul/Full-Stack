#include <iostream>
#include<algorithm>
#include<math.h>
#include<vector>
#include<cmath>
#include<stack>
using namespace std;

#define vi vector<int>

#define faster                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

const int MOD = 1000000007;      // 1e9 + 7
const int MAXN = 1000005;        // 1e6 +5
const int INF = 100000000000005; // 1e15 +5

vi dist;

set<pair<int, int>> q;

void bbfssutill(vi adj[], int s)
{
    set<pair<int, int>>::iterator it;

    for (int i = 0; i < adj[s].size(); i++)
    {
        int v = adj[s][i];
        if (dist[s] + 1 < dist[v])
        {

            it = q.find({dist[v], v});
            q.erase(it);
            dist[v] = dist[s] + 1;
            q.insert({dist[v], v});
        }
    }

    if (q.size() == 0)
        return;

    it = q.begin();
    int next = it->second;
    q.erase(it);

    bbfssutill(adj, next);
}

void bfs(vi adj[], int n, vi &s, int k)
{
    vi source(n + 1, 0);

    for (int i = 0; i < k; i++)
        source[s[i]] = 1;

    for (int i = 1; i <= n; i++)
    {
        if (source[i])
        {
            dist[i] = 0;
            q.insert({0, i});
        }
        else
        {
            dist[i] = INF;
            q.insert({INF, i});
        }
    }

    auto itr = q.begin();
    int start = itr->second;

    bbfssutill(adj, start);
}

void solve()
{
    int n, m, k, u, v, q;
    cin >> n >> m >> k;

    vi adj[n + 1], special(k);

    for (int i = 0; i < m; ++i)
    {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 0; i < k; ++i)
    {
        cin >> special[i];
    }

    dist = vi(n + 1, INF);
    bfs(adj, n, special, k);

    cin >> q;
    while (q--)
    {
        cin >> u;
        cout << (dist[u] >= INF ? -1 : dist[u]) << endl;
    }

    return;
}

signed main()
{
    faster;

    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}