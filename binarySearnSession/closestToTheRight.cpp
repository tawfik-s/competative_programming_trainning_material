// https://codeforces.com/edu/course/2/lesson/6/1/practice/contest/283911/problem/C
#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    int n, q;
    cin >> n >> q;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    for (int i = 0; i < q; i++)
    {
        int x;
        cin >> x;
        int l = 0, r = n;
        int ans = n;
        while (r >= l)
        {
            int mid = (l + r) / 2;
            if (v[mid] >= x)
            {
                ans = mid;
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }
        cout << ans + 1 << endl;
    }
}