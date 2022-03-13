#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int INF = 1e9;
// https://codeforces.com/group/jd9VOE1xdy/contest/372923/problem/C

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
#ifdef ONLINE_JUDGE
    freopen("nearest.in", "r", stdin);
#endif

    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        vector<ll> res;
        res.reserve(n);
        map<ll, ll> mp;
        set<ll> nset;
        set<ll> pset;
        for (int i = 0; i < n; i++)
        {
            ll a;
            cin >> a;
            if (i != 0)
            {
                ll x = *nset.lower_bound(-a);
                ll y = *pset.lower_bound(a);
                // cout<<a<<" "<<-x<<" "<<y<<endl;
                ll z = 0;
                if (abs(a + x) > abs(a - y))
                {
                    z = mp[y];
                }
                else
                {
                    z = mp[-x];
                }

                res.push_back(z);
            }
            mp[a] = i + 1;
            nset.insert(-a);
            pset.insert(a);
        }
        // cout<<endl;
        for (auto x : res)
        {
            cout << x << ' ';
        }
        cout << endl;
    }

    return 0;
}