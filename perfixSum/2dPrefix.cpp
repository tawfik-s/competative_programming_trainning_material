#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{

    int n, m, q;
    cin >> n >> q;
    m = n;
    vector<vector<ll>> v(n, vector<ll>(m, 0));
    vector<vector<ll>> prf(n + 1, vector<ll>(m + 1, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> v[i][j];
        }
    }
    for (int j = 1; j <= n; j++)
        for (int i = 1; i <= n; i++)
        {
            prf[i][j] = v[i - 1][j - 1] + prf[i - 1][j];
        }

    for (int j = 1; j <= n; j++)
        for (int i = 1; i <= n; i++)
        {
            prf[j][i] += prf[j][i - 1];
        }

    for (int j = 1; j <= n; j++)
    {
        for (int i = 1; i <= n; i++)
        {
            cout << prf[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
