#include <bits/stdc++.h>

using namespace std;
// https://codeforces.com/contest/1650/problem/C

typedef long long ll;
const int INF = 1e9;

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int t;
    cin >> t;
    bool flag = false;
    while (t--)
    {
        if (flag)
            cout << endl;
        flag = true;
        int n, m;
        cin >> n >> m;
        map<int, int> mp;
        vector<pair<int, int>> v(m);
        for (int i = 0; i < m; i++)
        {
            int a, b;
            cin >> a >> b;
            v[i] = {b, a};
            mp[a] = i + 1;
        }
        sort(v.begin(), v.end());
        ll sum = 0;
        vector<pair<int, int>> ans(2 * n);
        for (int i = 0; i < 2 * n; i++)
        {
            sum += v[i].first;
            ans[i] = {v[i].second, v[i].first};
        }
        sort(ans.begin(), ans.end());
        cout << sum << endl;
        for (int i = 0; i < n; i++)
        {
            cout << mp[ans[i].first] << " " << mp[ans.back().first] << endl;
            ans.pop_back();
        }
    }

    return 0;
}