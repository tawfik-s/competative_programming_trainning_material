#include <bits/stdc++.h>
// https://cses.fi/problemset/task/1646/

using namespace std;
typedef long long ll;

int main()
{

    int n, q;
    cin >> n >> q;
    vector<ll> v(n);
    vector<ll> prf(n + 1);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    for (int i = 1; i <= n; i++)
    {
        prf[i] = v[i - 1] + prf[i - 1];
    }

    while (q--)
    {
        int a, b;
        cin >> a >> b;
        ll sum = prf[b] - prf[a - 1];
        cout << sum << endl;
    }

    return 0;
}