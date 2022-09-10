#include <bits/stdc++.h>

typedef long long ll;
using namespace std;
int n;
int A = 0, B = 0;

vector<int> color;
vector<vector<int>> adj;
vector<bool> vis;
vector<int> ca, cb;

void dfs(int node)
{
    vis[node] = true;
    for (auto x : adj[node])
    {
        if (!vis[x])
        {
            dfs(x);
            ca[node] += ca[x];
            cb[node] += cb[x];
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    cin >> n;
    color.resize(n);
    adj.resize(n);
    ca.resize(n, 0);
    cb.resize(n, 0);
    vis.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin >> color[i];
        if (color[i] == 1)
        {
            A++;
            ca[i]++;
        }
        else if (color[i] == 2)
        {
            B++;
            cb[i]++;
        }
    }
    vector<pair<int, int>> edge;
    int counter = 0;
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        --a;
        --b;
        adj[a].push_back(b);
        adj[b].push_back(a);
        edge.push_back({a, b});
    }
    dfs(1);
    for (int i = 0; i < n - 1; i++)
    {
        int a = edge[i].first;
        int b = edge[i].second;

        if ((ca[a] <= ca[b] && cb[a] <= cb[b]))
        {
            swap(a, b);
        }

        pair<int, int> other = {A - ca[b], B - cb[b]};
        if ((other.first == 0 && cb[b] == 0) || (other.second == 0 && ca[b] == 0))
        {
            counter++;
        }
    }

    cout << counter << endl;

    return 0;
}