/*
author: tawfik shalash
─▄█▄─█▀█▀█─▄█▄
▀▀████▄█▄████▀▀
─────▀█▀█▀

*/
#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

int n, m;
vector<vector<int>> adj;
vector<int> vis;
vector<int> ans;
bool flag = true, cycleflag = false;
int nodesum = 0;
void dfs(int node)
{
    vis[node] = 1;
    nodesum++;
    for (auto x : adj[node])
    {
        if (vis[x] == 1)
        {
            cycleflag = true;
        }
        else if (!vis[x])
        {
            dfs(x);
        }
    }
    ans.push_back(node);
    vis[node] = 2;
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int T;
    cin >> T;
    while (T--)
    {
        flag = true;
        ans.clear();
        vis.clear();
        adj.clear();
        cin >> n;
        vis.resize(n, 0);
        adj.resize(n);
        vector<int> num(n, 0);

        for (int i = 0; i < n; i++)
        {
            int a, b;
            cin >> a >> b;
            --a;
            --b;
            adj[a].push_back(b);
            adj[b].push_back(a);
            num[a]++;
            num[b]++;
        }
        for (int i = 0; i < n; i++)
        {
            if (num[i] > 2)
            {
                flag = false;
                break;
            }
            else
            {
                nodesum = 0;
                if (!vis[i])
                {
                    dfs(i);
                    if (cycleflag && nodesum % 2 == 1)
                    {
                        flag = false;
                        break;
                    }
                }
            }
        }
        if (flag)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }

    return 0;
}