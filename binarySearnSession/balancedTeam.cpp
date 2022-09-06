// https://codeforces.com/problemset/problem/1133/C
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
#define int long long
int n;
vector<int> v;

bool can(int segsize)
{
    for (int i = 0; i < n - segsize + 1; i++)
    {
        if (v[i + segsize - 1] - v[i] <= 5)
        {
            return true;
        }
    }
    return false;
}

int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    cin >> n;
    v.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    sort(v.begin(), v.end());

    int l = 1;
    int r = n;
    int ans = 1;
    while (r >= l)
    {
        int mid = (r + l) >> 1;
        if (can(mid))
        {
            ans = mid;
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }
    }
    cout << ans << endl;

    return 0;
}