// https://codeforces.com/edu/course/2/lesson/6/1/practice/contest/283911/problem/D

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
#define int long long

int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    int q;
    cin >> q;
    sort(v.begin(), v.end());
    while (q--)
    {
        int a, b;
        cin >> a >> b;
        int r = n, l = n;
        int la = 0;
        int ra = n - 1;
        while (la <= ra)
        {
            int mid = (la + ra) / 2;
            if (v[mid] >= a)
            {
                l = mid;
                ra = mid - 1;
            }
            else
            {
                la = mid + 1;
            }
        }
        la = 0;
        ra = n - 1;
        while (la <= ra)
        {
            int mid = (la + ra) / 2;

            if (v[mid] > b)
            {
                ra = mid - 1;
            }
            else
            {
                la = mid + 1;
            }
        }
        r = la;
        if (la < n && v[la] <= b)
        {
            r++;
        }
        cout << r - l << endl;
    }

    return 0;
}