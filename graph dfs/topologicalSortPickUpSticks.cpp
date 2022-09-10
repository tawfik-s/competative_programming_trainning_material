// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2733

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
int n, m;
vector<vector<int>> adjlist;
vector<int> ans;
vector<int> vis;
bool flag = true;
void dfs(int node)
{
    vis[node] = 1;
    for (auto x : adjlist[node])
    {
        if (!vis[x])
        {
            dfs(x);
        }
        else if (vis[x] == 1)
        {
            flag = false;
            return;
        }
    }
    ans.push_back(node);
    vis[node] = 2;
}

int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    while (cin >> n >> m)
    {
        vis.clear();
        adjlist.clear();
        ans.clear();
        flag = true;

        vis.resize(n, 0);
        adjlist.resize(n);
        for (int i = 0; i < m; i++)
        {
            int a, b;
            cin >> a >> b;
            --a;
            --b;
            adjlist[a].push_back(b);
        }
        for (int i = 0; i < n; i++)
        {
            if (!vis[i])
            {
                dfs(i);
            }
            if (!flag)
            {
                break;
            }
        }
        reverse(ans.begin(), ans.end());
        if (!flag)
        {
            cout << "IMPOSSIBLE" << endl;
        }
        else
            for (int i = 0; i < ans.size(); i++)
            {
                cout << ans[i] + 1 << endl;
            }
    }

    return 0;
}